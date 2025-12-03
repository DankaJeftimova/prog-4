#include <bits/stdc++.h>
using namespace std;


class GermanString {
private:
    char* text;
    int32_t size;
    char* prefix;

public:
    GermanString() {
        size = 0;
        text = nullptr;
        prefix = nullptr;
    } 

    GermanString(const char* str) {
        if (str) {
            size = strlen(str);

            if(size <= 12)
            {
                text = new char[size + 1];
                prefix = new char[5];

                for (int i = 0; i < size; i++) 
                text[i] = str[i];

                text[size] = '\0';

                for(int i=0; i<4; i++)
                prefix[i]=str[i];

                prefix[4] = '\0';
            }
            else
            {
                text = new char[size + 1];
                prefix = nullptr;

                for (int i = 0; i < size; i++) 
                text[i] = str[i];

                text[size] = '\0';

            }

        
        
        } 
        else {
            text = nullptr;
            prefix = nullptr;
            size = 0;
        }
    }

    GermanString(const GermanString& other) {
        size = other.size;
        if (size > 0) {
            text = new char[size + 1];
            prefix = new char [5];
            for (int i = 0; i < size; i++) 
                text[i] = other.text[i];

            for (int i = 0; i < 4; i++) 
                prefix[i] = other.prefix[i];

            text[size]='\0';
            prefix[4] = '\0';
        }
        else {
            text = nullptr;
            prefix = nullptr;
        }
    }


    GermanString& operator=(const GermanString& other) {
        if (this == &other) return *this;

        delete[] text;
        delete [] prefix;
        size = other.size;

        if (size > 0) {
            text = new char[size + 1];
            prefix = new char [5];
            for (int i = 0; i < size; i++) 
                text[i] = other.text[i];

            for (int i = 0; i < 4; i++) 
                prefix[i] = other.prefix[i];

            text[size]='\0';
            prefix[4] = '\0';
        }
        else {
            text = nullptr;
            prefix = nullptr;
        }

        return *this;
    }

    ~GermanString() {
        delete[] text;

        if(prefix)
        delete[] prefix;
    }

    int size_of()
    {
        return size;
    }

    void print()
    {
        for (int i = 0; i < size; i++) 
            cout << text[i];

        cout << '\n';
    }

    void empty()
    {
        size = 0;
        delete [] text;

        text = nullptr;

        if(prefix)
        delete [] prefix;

        prefix = nullptr;
    }

};


int main()
{
    GermanString s("danka");

    cout << s.size_of();
    cout << endl;

    s.print();

    return 0;
}