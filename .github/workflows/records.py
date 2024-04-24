import sys
import os
from datetime import date, datetime, timedelta

input_file = sys.argv[1]
output_file = sys.argv[2]
project_root = sys.argv[3]

dc = {}
if os.path.exists(input_file):
    print('Found existing input file ' + input_file)
    with open(input_file, 'r') as f:
        for line in f.readlines():
            line = line.strip()
            if ':' not in line:
                continue
            k, v = line.split(':')
            dc[k] = v
else:
    print('Cannot find existing input file ' + input_file)

current_date = date(2024, 2, 25)
if 'current_date' in dc.keys():
    dt = datetime.strptime(dc['current_date'], '%Y-%m-%d')
    current_date = date(dt.year, dt.month, dt.day)
    if current_date < date(2024, 3, 8):
        print('Full re-calculate by intention')
        current_date = date(2024, 2, 25)
        dc = {}
latest_date = current_date

users = {}
for k, v in dc.items():
    if k == 'current_date' or k == 'skipped_dates':
        continue
    users[k] = list(map(lambda s: list(map(int, s.split(','))), v.split('/')))

skipped_dates = []
if 'skipped_dates' in dc.keys():
    y, m, d = 0, 0, 0
    for s in dc['skipped_dates'].split(','):
        if s[0] == 'y':
            y = int(s[1:])
        elif s[0] == 'm':
            m = int(s[1:])
        else:
            for i in range(0, len(s), 2):
                d = int(s[i:i + 2])
                skipped_dates.append('%d%02d%02d' % (y, m, d))

yesterday = date.today() - timedelta(days = 1)
while current_date < yesterday:
    current_date += timedelta(days = 1)
    dirname = '%s/daily_problems/%d/%02d/%02d%02d/personal_submission' % (project_root, current_date.year, current_date.month, current_date.month, current_date.day)
    if not os.path.exists(dirname):
        skipped_dates.append('%d%02d%02d' % (current_date.year, current_date.month, current_date.day))
        continue

    submissions = {}
    for filename in os.listdir(dirname):
        if not '_' in filename:
            continue
        lst = filename.split('.')[0].split('_')
        pid, uid = lst[0].lower(), '_'.join(lst[1:]).lower()
        if uid.endswith('_star'):
            uid = uid[:-5]
        if uid not in submissions.keys():
            submissions[uid] = set()
        submissions[uid].add(pid)
    
    for uid, lst in users.items():
        if uid in submissions.keys():
            sz = min(2, len(submissions[uid]))
        else:
            sz = 0
        if lst[-1][0] == sz:
            lst[-1][1] += 1
        else:
            lst.append([sz, 1])
    
    for uid, st in submissions.items():
        sz = min(2, len(st))
        if uid not in users.keys():
            users[uid] = [[sz, 1]]
    
    latest_date = current_date

with open(output_file, 'w') as f:
    f.write('let records = `\n')
    f.write('current_date:%s\n' % latest_date.strftime('%Y-%m-%d'))
    for uid, lst in users.items():
        s = '/'.join(map(lambda p: str(p[0]) + ',' + str(p[1]), lst))
        f.write('%s:%s\n' % (uid, s))

    f.write('skipped_dates:')
    y, m = 0, 0
    lst = []
    for s in skipped_dates:
        if s > '%d%02d%02d' % (latest_date.year, latest_date.month, latest_date.day):
            break
        yy, mm, dd = int(s[:4]), int(s[4:6]), int(s[6:])
        if y != yy:
            lst.append('y%d' % yy)
            y = yy
        if m != mm:
            lst.append('m%d' % mm)
            m = mm
        if lst[-1][0] == 'y' or lst[-1][0] == 'm':
            lst.append('')
        lst[-1] += '%02d' % dd
    f.write(','.join(lst))
    f.write('\n')

    f.write('`;\n')
