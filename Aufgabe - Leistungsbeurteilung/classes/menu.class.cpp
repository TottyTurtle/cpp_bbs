struct Menu {
    map<int, string> map_key;
    map<int, string> map_value;
    int menu_num = 0
        ,menusize = 0;

    string key;

    void init() {
        menu_num = 0;
    }

    int add(string key, string value) {
        menusize = map_value.size();
        map_key[menusize] = key;
        map_value[menusize] = value;
    }

    void change(int change) {
        if(change) {
            menu_num += change;
        } else {
            menu_num -= change;
        }

        menu_num = menu_num < 0 ? 0 : menu_num;
        menu_num = menu_num > menusize ? menusize : menu_num;
    }

    string getKey() {
        return key;
    }

    int show(string text) {
        system("cls");
        cout << text << endl << endl;
        int num = 0;
        for (auto it = map_value.begin(); it != map_value.end(); ++it) {
            if(menu_num == num) {
                cout << "[X]" << it->second << endl;
                key = map_key.at(num);
            } else {
                cout << "[ ]" << it->second << endl;
            }
            num++;
        }

        //cout << (menu_num == 4 ? "[X]" : "[ ]") << "Element 3" << endl;
    }
};





