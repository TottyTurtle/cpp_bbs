struct Exam {
    string path;
    json jfile;
    int rid = 0;
    int aid = 0;

    void setTitle(string title) {
        path = regex_replace(title, regex(" "), "_") + ".json";

        jfile["title"] = title;
    }

    int addRequest(string type, string request) {
        jfile["request"][rid]["type"] = type;
        jfile["request"][rid]["request"] = request;
        aid = 0;
        return rid++;
    }

    void addAnswer(int id, string answer) {
        jfile["request"][id]["answer"][aid++] = answer;
    }

    void getRequest() {
        for (auto& [rkey, req] : jfile["request"].items()) {
            int ikey = stoi(rkey) + 1;
            cout << endl << "Frage " << ikey << ": " <<req["request"] << endl;
            if(req["type"] == "text") {
            cout << "Antworten: Freitext" << endl;
                continue;
            }
            cout << "Antworten: " << endl;
            for (auto& [rans, ans] : req["answer"].items()) {
            int ians = stoi(rans) + 1;
                cout << ians << ": " << ans << endl;
            }
        }
    }

    string getTypeFrom(string key) {
        if(key == "\"single\"") {
            return "Single Choice";
        } else if(key == "\"multiple\"") {
            return "Multiple Choice";
        } else if(key == "\"text\"") {
            return "Freitextfrage";
        }
        return key;
    }

    json getJson() {
        return jfile;
    }

    void save() {
        fstream f;
        f.open("exam/" + path, ios::out);
        f << jfile;
        f.close();
    }
    void load(string file) {
        path = file;
        fstream f;
        f.open("exam/" + file, ios::in);
        string s;
        getline(f, s);
        f.close();

        jfile = json::parse(s);;
    }
};





