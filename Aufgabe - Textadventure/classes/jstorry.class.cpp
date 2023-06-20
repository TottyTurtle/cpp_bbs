class JStorry {
    private:
        string id,
               path;
        json jsonfile;
        json jsonvar;
        int choiseid = -1;
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

            for (auto& [key, value] : jjson[0]["variables"].items()) {

                int type = value["type"].get<std::int64_t>();
                jsonvar[key]["type"] = type;
                switch(type) {
                    case 0://String
                            jsonvar[key]["type"] = value["value"].get<std::string>();
                        break;
                    case 1://Int
                            jsonvar[key]["type"] = value["value"].get<int>();
                        break;
                    case 2://Boolean
                            jsonvar[key]["type"] = value["value"].get<bool>();
                        break;
                }
            }
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
                    jsonfile[nodename]["isbox"] = value["is_box"].get<bool>();
                    jsonfile[nodename]["character"] = value["character"];

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
            if(this->choiseid != -1) {
                this->id = jsonfile[this->id]["choices"][to_string(this->choiseid)]["next"].get<std::string>();
                this->choiseid = -1;
                return;
            }
            this->id = jsonfile[this->id]["next"].get<std::string>();
        }

        bool isChoise() {
            return jsonfile[this->id]["type"].get<std::string>() == "show_choices";
        }
        bool isBox() {
            return jsonfile[this->id]["isbox"].get<bool>();
        }

        string getChoise(string id) {
            return jsonfile[this->id]["choices"][id]["text"].get<std::string>();
        }

        string getCharacter() {
            return jsonfile[this->id]["character"][0].get<std::string>();
        }

        void setChoise(int id) {
           this->choiseid = id;
        }

        int getChoiseSize() {
            return jsonfile[this->id]["choices"].size();
        }


        string getText() {
            if(jsonfile[this->id]["text"].is_null()) {
                return "error";
            }
            return jsonfile[this->id]["text"].get<std::string>();
        }
};
