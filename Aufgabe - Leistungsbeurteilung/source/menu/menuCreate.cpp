Menu menu_create;
Exam exam;

init_menuCreate() {
    menu_create.add("single", "Add Single Choice");
    menu_create.add("multiple", "Add Multiple Choice");
    menu_create.add("text", "Add Freitextfrage");
    menu_create.add("edit", "Editieren");
    menu_create.add("save", "Speichern & Exportieren");
}

void editItem(Menu menu_request) {
    json jfile = exam.getJson();
    cout << "Edit: "<< menu_request.getValue() << endl;
    string text;
    getline(cin, text);
    for (auto& [rkey, req] : jfile["request"].items()) {
        if(menu_request.getKey() == rkey) {
            exam.editRequest(stoi(rkey), text);
            break;
        }
        if(req["type"] == "text") {
            continue;
        }
        for (auto& [rans, ans] : req["answer"].items()) {
            if(menu_request.getKey() == (rkey + "_" + rans)) {
                exam.editAnswer(stoi(rkey), stoi(rans), text);
                break;
            }
        }
    }
}
void editRequest() {
    Menu menu_request;
    json jfile = exam.getJson();
    for (auto& [rkey, req] : jfile["request"].items()) {
        int ikey = stoi(rkey) + 1;

        menu_request.add(rkey, exam.getTypeFrom(req["type"].dump()) + ": " + req["request"].dump());
        if(req["type"] == "text") {
            continue;
        }
        for (auto& [rans, ans] : req["answer"].items()) {
        int ians = stoi(rans) + 1;
            menu_request.add(rkey + "_" + rans, "- " + ans.dump());
        }
    }
    menu_request.show("Editieren: ");
    while(true) {

        int key = getKey();
        if(key == 27) { //ESC
            break;
        } else if(key == 72) {
            menu_request.change(-1);
        } else if(key == 80) {
            menu_request.change(1);
        } else if(key == 13) {
            editItem(menu_request);
            return;
        }
        menu_request.show("Editieren: ");
    }
    //exam.getRequest();
    //cout << endl << "Zum Editieren: <Frage ID> <Antwort ID> <Text>" << endl;
    //string asd;
    //getline(cin, asd);

}

int enterCreateMenu() {
    if(menu_create.getKey() == "save") {
        exam.save();
        string filename = TEXT("page/" + regex_replace(exam.getData(), regex(".json"), "") + ".html");
        copyFile( TEXT("template.html"), filename);

        prependStringToFile(filename, "<script type=\"text/javascript\">var jsonData = '" + exam.getJson().dump() + "'; </script>");
        return 1;
    }
    if(menu_create.getKey() == "edit") {
        editRequest();
        return 0;
    }
    string value;
    cout << endl << "Gib eine Frage ein: ";

    getline(cin, value);

    cout << endl;
    int id = exam.addRequest(menu_create.getKey(), value);

    if(menu_create.getKey() == "text") {
        return 0;
    }
    cout << "Gibt \"exit\" um die Frage fertigzustellen." << endl;
    int num = 1;
    while(true) {
        cout << "Antwortmöglichkeit " << num <<": ";
        string answer;
        getline(cin, answer);
        if(answer == "exit") {
            break;
        }
        exam.addAnswer(id, answer);
        num++;
    }
    return 0;
}
void menuCreate(string file) {
    Exam nexam;
    exam = nexam;

    menu_create.init();
    string name;
    system("cls");


    if(file != "") {
        exam.load(file);
    } else {
        cout << "Erstellen." << endl << endl;

        cout << "Bitte gib einen Title an: ";
        //cin.clear();
        //cin.ignore(200, '\n');
        getline(cin, name);
        /*name = replace(name, "ä", "aa");
        name = replace(name, "ö", "oo");
        name = replace(name, "ü", "uu");*/
        exam.setTitle(name);
    }


    menu_create.show("Erstellen: " + name);
    while(true) {

        int key = getKey();
        if(key == 27) { //ESC
            return;
        } else if(key == 72) {
            menu_create.change(-1);
        } else if(key == 80) {
            menu_create.change(1);
        } else if(key == 13) {
            if(enterCreateMenu() == 1) {
                return;
            }
        }
        menu_create.show("Erstellen: " + name);
    }
}
