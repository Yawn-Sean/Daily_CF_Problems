bool inside(vector<double>& Ax, vector<double>& Ay, vector<double>& Bx, vector<double>& By) {
    double minX = *min_element(all(Ax));
    double maxX = *max_element(all(Ax));
    double minY = *min_element(all(Ay));
    double maxY = *max_element(all(Ay));
    //cout << minX << " " << maxX << " " << minY << " " << maxY << endl;
    for (int i = 0; i < sz(Bx); i++) {
        //cout << Bx[i] << " " << By[i] << endl;
        bool checkX = (Bx[i] >= minX && Bx[i] <= maxX);
        bool checkY = (By[i] >= minY && By[i] <= maxY);
        if (checkX && checkY) {
            return true;
        }
    }
    return false;
}
 
void solve() {
    vector<double> Ax(4), Bx(4), Ay(4), By(4);
    for (int i = 0; i < 4; i++) {
        cin >> Ax[i] >> Ay[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> Bx[i] >> By[i];
    }
    vector<double> extendX = Bx, extendY = By;
    for (int i = 0; i < 4; i++) {
        int next = (i + 1) % 4;
        double midX = min(Bx[i], Bx[next]) + (max(Bx[i], Bx[next]) - min(Bx[i], Bx[next])) / 2.0;
        double midY = min(By[i], By[next]) + (max(By[i], By[next]) - min(By[i], By[next])) / 2.0;
        extendX.emplace_back(midX);
        extendY.emplace_back(midY);
    }
    if (inside(Ax, Ay, extendX, extendY)) {
        //cout << "here" << endl;
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < 4; i++) {
        double nX = (Ax[i] - Ay[i]) / 2.0;
        double nY = (Ax[i] + Ay[i]) / 2.0;
        Ax[i] = nX, Ay[i] = nY;
    }
    for (int i = 0; i < 4; i++) {
        double nX = (Bx[i] - By[i]) / 2.0;
        double nY = (Bx[i] + By[i]) / 2.0;
        Bx[i] = nX, By[i] = nY;
    }
    extendX = Ax;
    extendY = Ay;
    for (int i = 0; i < 4; i++) {
        int next = (i + 1) % 4;
        double midX = min(Ax[i], Ax[next]) + (max(Ax[i], Ax[next]) - min(Ax[i], Ax[next])) / 2.0;
        double midY = min(Ay[i], Ay[next]) + (max(Ay[i], Ay[next]) - min(Ay[i], Ay[next])) / 2.0;
        extendX.emplace_back(midX);
        extendY.emplace_back(midY);
    }
    if (inside(Bx, By, extendX, extendY)) {
        //cout << "here1" << endl;
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
