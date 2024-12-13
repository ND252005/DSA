G = new bool* [v];
    
    for(int i = 0; i < v; i++) {
        G[i] = new bool [v] {0};
    }

    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        G[x - 1][y - 1] = 1;
    }

    // for(int i = 0; i < v; i++) {
    //     for(int j = 0; j < v; j++) {
    //         cout << G[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    for(int i = 0; i < n; i++) {
        int x; cin >> x; 
        if(x == 1) {
            int y, z; cin >> y >> z;
            if(G[y - 1][z - 1] == 1) cout << "TRUE" << endl;
            if(G[y - 1][z - 1] == 0) cout << "FALSE" << endl;
        }
        else if(x == 2) {
            int y; cin >> y;
            bool dem = false;
            for(int i = 0; i < v; i++) {
                if(G[y - 1][i] == 1) {
                    cout << i + 1 << ' ';
                    dem = true;
                }
            }
            if(!dem) cout << "NONE";
            cout << endl;
        }
    }

}   