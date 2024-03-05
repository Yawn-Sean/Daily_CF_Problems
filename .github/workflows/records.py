import sys
import os
from datetime import date, datetime, timedelta

input_file = sys.argv[1]
output_file = sys.argv[2]
project_root = sys.argv[3]

d = {}
if os.path.exists(input_file):
    with open(input_file, 'r') as f:
        for line in f.readlines():
            line = line.strip()
            if ':' not in line:
                continue
            k, v = line.split(':')
            d[k] = v

users = {}
for k, v in d.items():
    if k == 'current_date':
        continue
    users[k] = list(map(lambda s: list(map(int, s.split(','))), v.split('/')))

current_date = date(2024, 2, 25)
if 'current_date' in d.keys():
    current_date = datetime.strptime(d['current_date'], '%Y-%m-%d')
latest_date = current_date

yesterday = date.today() - timedelta(days = 1)
while current_date < yesterday:
    current_date += timedelta(days = 1)
    dirname = '%s/daily_problems/%d/%02d/%02d%02d/personal_submission' % (project_root, current_date.year, current_date.month, current_date.month, current_date.day)
    if not os.path.exists(dirname):
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
    f.write('`;\n')
