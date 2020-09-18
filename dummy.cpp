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
} detail[100];

void display()
{
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
        int i = 0, size = 0;
        while (!fin.eof())
        {
            getline(fin, detail[i].song, ',');
            getline(fin, detail[i].artist, ',');
            getline(fin, detail[i].album, ',');
            getline(fin, detail[i].genre, '\n');
            i++;
            size++;
        }
        cout<<"artist\t\talbum\t\tsong\t\t\tgenre"<<endl;
        for (i = 0; i < size; i++)
        {
            cout << detail[i].artist<< "\t\t"<<detail[i].album<< "\t\t" << detail[i].song<< "\t"<< detail[i].genre << endl;
        }
    }

    fin.close();
}

int main()
{
    display();
    /*string search;
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
        int i = 0, count = 0;
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

    fin.close();*/
    return 0;
}