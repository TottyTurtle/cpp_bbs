class JStorry {
    private:
        string path;
        json jsonfile;
        string id;
    public:
        JStorry(string path){
            this->path = path;

            fstream f;
            f.open(this->path, ios::in);
            string s;
            getline(f, s);
            f.close();

            json jjson = json::parse(s);
            string nodename, next;

            for (auto& [i, value] : jjson[0]["nodes"].items()) {
                next = "end";

                string type = value["node_type"].get<std::string>();
                nodename = value["node_name"].get<std::string>();


                if(type == "execute") {
                    jsonfile[nodename]["type"] = type;
                    if(!value["next"].is_null()) {
                        next = value["next"].get<std::string>();
                    }
                    jsonfile[nodename]["next"] = next;
                    jsonfile[nodename]["text"] = value["text"].get<std::string>();

                    continue;
                } else if(type == "start") {
                    jsonfile[nodename]["type"] = type;
                    if(!value["next"].is_null()) {
                        next = value["next"].get<std::string>();
                    }
                    jsonfile[nodename]["next"] = next;

                    continue;
                } else if(type == "show_message") {
                    if(!value["next"].is_null()) {
                        next = value["next"].get<std::string>();
                    }
                    jsonfile[nodename]["next"] = next;

                    if(!value["text"]["DE"].is_null()) {
                        jsonfile[nodename]["text"] = value["text"]["DE"].get<std::string>();
                    } else {
                        jsonfile[nodename]["text"] = value["text"].get<std::string>();
                    }

                    if(value["choices"].is_null()) {
                        jsonfile[nodename]["type"] = type;
                        continue;
                    }

                    jsonfile[nodename]["type"] = "show_choices";
                    for (auto& [j, value2] : value["choices"].items()) {
                        jsonfile[nodename]["choices"][j]["next"] = value2["next"].get<std::string>();
                        jsonfile[nodename]["choices"][j]["text"] = value2["text"]["DE"].get<std::string>();
                    }

                    continue;
                }

            }
        }

        void setNext(string id) {
            this->id = id;
        }

        void next() {
            this->id = jsonfile[this->id]["next"].get<std::string>();
        }

        bool isChoise() {
            return jsonfile[this->id]["type"].get<std::string>() == "show_choices";
        }

        string getChoise(string id) {
            return jsonfile[this->id]["choices"][id]["text"].get<std::string>();
        }
        string getText() {
            if(jsonfile[this->id]["text"].is_null()) {
                return "error";
            }
            return jsonfile[this->id]["text"].get<std::string>();
        }
};
