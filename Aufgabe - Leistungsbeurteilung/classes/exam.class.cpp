struct Exam {
    string path;
    json jfile;
    int rid = 0;
    int aid = 0;

    void setTitle(string ttitle) {
        path = regex_replace(ttitle, regex(" "), "_") + ".json";
        jfile["title"] = ttitle;
    }
    string uml(string text) {
        text = regex_replace(text, regex("ä"), "&auml;");
        text = regex_replace(text, regex("ö"), "&ouml;");
        text = regex_replace(text, regex("ü"), "&uuml;");
        text = regex_replace(text, regex("Ä"), "&Auml;");
        text = regex_replace(text, regex("Ö"), "&Ouml;");
        text = regex_replace(text, regex("Ü"), "&Uuml;");
        text = regex_replace(text, regex("ß"), "&szlig;");
        return text;
    }
    int addRequest(string type, string request) {
        jfile["request"][rid]["type"] = type;
        jfile["request"][rid]["request"] = uml(request);
        aid = 0;
        return rid++;
    }
    void editRequest(int id, string request) {
        jfile["request"][id]["request"] = uml(request);
    }
    void addAnswer(int id, string answer) {
        jfile["request"][id]["answer"][aid++] = uml(answer);
    }

    void editAnswer(int id, int aid, string answer) {
        jfile["request"][id]["answer"][aid] = uml(answer);
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


    string getData() {
        return path;
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





