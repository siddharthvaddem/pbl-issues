#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

struct info
{
    string artist;
    string album;
    string song;
    string genre;
};

int main()
{
    string search;
    cout << "Enter the name of the song to be searched for:" << endl;
    cin >> search;
    ifstream fin;
    fin.open("dummy.csv");
    string read, id, artist, album, genre, song;
    bool notfound = true;
    if (!fin)
    {
        cout << "file could not be opened" << endl;
    }
    else
    {
        while (!fin.eof())
        {
            getline(fin, read, ',');
            if (read == search)
            {
                notfound = false;
                song = read;
                getline(fin, artist, ',');
                getline(fin, album, ',');
                getline(fin, genre, '\n');
            }
            else
            {
                getline(fin, read);
            }
        }
        if (notfound)
        {
            cout << "Song not found" << endl;
        }
        else
        {
            cout << "artist- " << artist;
            cout << "\n";
            cout << "album- " << album;
            cout << "\n";
            cout << "song- " << song;
            cout << "\n";
            cout << "genre- " << genre;
        }
    }

    fin.close();
    return 0;
}