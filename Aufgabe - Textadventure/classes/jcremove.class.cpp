class JCRemove {
    private:
        COORD pos={0, 0};
        CONSOLE_SCREEN_BUFFER_INFO info;
    public:
        JCRemove(){

        }

        void setPoint() {
            HANDLE handle=GetStdHandle (STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO info;

            if (GetConsoleScreenBufferInfo(handle, &info))
            {
                pos=info.dwCursorPosition;
            }
        }

        void removeLine()
        {
            HANDLE handle=GetStdHandle (STD_OUTPUT_HANDLE);

            DWORD dw;

            cout.flush ();
            GetConsoleScreenBufferInfo (handle, &info);

            cout.flush ();
            FillConsoleOutputAttribute (handle, info.wAttributes, info.dwSize.X*info.dwSize.Y, pos, &dw);
            cout.flush ();
            FillConsoleOutputCharacter (handle, ' ', info.dwSize.X*info.dwSize.Y, pos, &dw);

            cout.flush ();
            SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), pos);

        }
};

