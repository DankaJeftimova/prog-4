#include <bits/stdc++.h>

using namespace std;


void print(vector<string> & v)
{
    cout << "\033[2J\033[H";
    cout << "Controls  :s - to save progress, :d#num - to delete a line with number num, :q to quit, #num - to edit line number num" << '\n';

    cout << "-------------------------------------------------------------------"<<'\n';

    int count=1;

    for(auto i:v)
    {
        cout << count << ' ';
        cout << i << '\n';
        count++;
    }

    cout << "-------------------------------------------------------------------"<<'\n';

    return;
}


int main()
{
    vector<string> buffer;

    ifstream file("document.txt");

    string one_line="";
    while( getline(file, one_line))
    {
        buffer.push_back(one_line);
    }

    file.close();

    while(true)
    {
        print(buffer);

        string input="";

        getline(cin, input);

        if(input == ":q")
        {
            break;
        }   

        if(input == ":s")
        {
            ofstream out("document.txt");

            for(auto i:buffer)
            out<<i<<'\n';

            out.close();

            cout << "Saved";

            continue;
        }

        if (input.size() >= 4 && input.substr(0, 3) == ":d#" && isdigit(input[3])) 
        {
    
            string broj = input.substr(3);
            int index = stoi(broj) - 1;

    
            if (index >= 0 && index < buffer.size()) 
            {
                buffer.erase(buffer.begin() + index);
            } 
                
            else 
            {
                cout << "Invalid line number!" << endl;
            }
                continue; 
        }

        if(input.size()>=2 and input[0]=='#' and isdigit(input[1]))
        {
            string broj = "";
            broj.push_back(input[1]);
            int i = 2;
            while(i<input.size() and isdigit(input[i]) )
            {
                broj.push_back(input[i]);
                i++;
            }

            int br = stoi(broj)-1;

            if(br>=0 and br<buffer.size())
            {
                cout << "Editing line " << br+1 << ": " << '\n';
                string newl = "";
                getline(cin, newl);

                buffer[br] = newl;
                continue;

            }

            
        }

        buffer.push_back(input);
    }


    return 0;
}