#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

typedef struct info
{
    string artist[100];
    string album[100];
    string song[100];
    string genre[100];
} Info;

Info data, filtered, temp;
string trash;
struct playlist
{
    Info playlist_data;
    struct node *next;
};

int size = 0;

void create_playlist_menu();
void edit_record_menu();
void display_record_menu();
void display_all_records();
void play_playlist_menu();
void filter_records();

int main()
{
lbl:
    int choice, subchoice;
    cout << "MENU\n";
    cout << "1>Create playlist" << endl;
    cout << "2>Display records" << endl;
    cout << "3>Edit records" << endl;
    cout << "4>Play Playlist" << endl;
    cout << "5>Exit" << endl;
    cout << "Enter your choice:";
    cin >> choice;
    cout << endl;
    switch (choice)
    {

    case 1: //fucntion1
        create_playlist_menu();

        break;
    case 2: //function2
        display_record_menu();
        break;
    case 3: //function3
        edit_record_menu();
        break;
    case 4: //function4
        play_playlist_menu();
        break;

    case 5: //function5
        exit(0);
        break;

    default:
        cout << "Invalid Input." << endl;
    }
    goto lbl;
    return 0;
}
void create_playlist_menu()
{
    /*string name, song_name;
    playlist *head = new playlist;
    cout << "Enter the name of the file:";
    cin >> name;
    cout << endl;
    display_all_records();
    cout << "Enter the name of the song to be added:";
    cin >> song_name;
    bool notfound = true;
    for (int i = 0; i < size; i++)
    {
        if (data.song[i] == song_name)
        {
            playlist *new_song = new playlist;
            new_song->playlist_data.song = data.song[i];
            new_song->playlist_data.album = data.album[i];
            new_song->playlist_data.artist = data.artist[i];
            new_song->playlist_data.genre = data.genre[i];
        }
    }*/
}

void edit_record_menu()
{
lbl:
    int subchoice;
    cout << "Edit records Menu" << endl;
    cout << "1>Insert record" << endl;
    cout << "2>Delete record" << endl;
    cout << "3>Return to main menu" << endl;
    cout << "Enter your choice:";
    cin >> subchoice;
    cout << endl;
    switch (subchoice)
    {
    case 1: //subfunction1
        cout << "Insert record" << endl;
        break;
    case 2: //subfunction2
        cout << "Delete record" << endl;
        break;
    case 3:
        return;
        break;
    default:
        cout << "Invalid Input" << endl;
        goto lbl;
    }
}

void display_record_menu()
{
lbl:
    int subchoice;

    cout << "Display records" << endl;
    cout << "1>Display all records" << endl;
    cout << "2>Filter" << endl;
    cout << "3>Return to main menu" << endl;
    cout << "Enter your choice:";
    cin >> subchoice;
    cout << endl;

    switch (subchoice)
    {
    case 1: //subfunction1
        cout << "all records" << endl;
        cout << endl;
        display_all_records();
        break;
    case 2: //subfunction2
        filter_records();
        break;

    case 3:
        return;
        break;
    default:
        cout << "Invalid Input" << endl;
    }
    goto lbl;
}

void filter_records()
{
    int Subchoice;
lbl2:
    string read, search;
    ifstream fin;
    bool notfound = true;
    int i = 0, a = 0;
    cout << "Filter by -" << endl;
    cout << "1>Artist " << endl;
    cout << "2>Song  " << endl;
    cout << "3>Album " << endl;
    cout << "4>Genre " << endl;
    cout << "5>Return to previous menu" << endl;
    cout << "Enter your choice: ";
    cin >> Subchoice;
    cout << endl;
    switch (Subchoice)
    {
    case 1: //filter by artist

        fin.open("dummy.csv");
        if (!fin)
        {
            cout << "file could not be opened" << endl;
        }
        else
        {
            cout << "Enter the name of the artist:";
            cin >> search;
            cout << endl;
            while (!fin.eof())
            {

                getline(fin, temp.song[i], ',');
                getline(fin, temp.album[i], ',');
                getline(fin, read, ',');
                if (read == search)
                {

                    notfound = false;
                    filtered.song[i] = temp.song[i];
                    filtered.album[i] = temp.album[i];
                    filtered.artist[i] = read;
                    getline(fin, temp.genre[i], '\n');
                    filtered.genre[i] = temp.genre[i];
                    if (a == 0)
                    {
                        cout << " Results for " << filtered.artist[i] << "-" << endl;
                        cout << "song" << setw(30) << "album" << setw(30) << "genre" << endl;
                        a++;
                    }
                    cout << filtered.song[i] << setw(30) << filtered.album[i] << setw(30) << filtered.genre[i] << endl;
                }
                else
                {
                    getline(fin, trash, '\n');
                }
                i++;
            }
            if (notfound)
            {
                cout << "No results found" << endl;
            }
        }
        fin.close();
        break;
    case 2: //filter by song
        fin.open("dummy.csv");
        if (!fin)
        {
            cout << "file could not be opened" << endl;
        }
        else
        {
            cout << "Enter the name of the song:";
            cin >> search;
            cout << endl;
            while (!fin.eof())
            {

                getline(fin, read, ',');
                if (read == search)
                {

                    notfound = false;
                    filtered.song[i] = read;
                    getline(fin, temp.album[i], ',');
                    getline(fin, temp.artist[i], ',');
                    getline(fin, temp.genre[i], '\n');
                    filtered.album[i] = temp.album[i];
                    filtered.artist[i] = temp.artist[i];
                    filtered.genre[i] = temp.genre[i];
                    if (a == 0)
                    {
                        cout << "Results for " << filtered.song[i] << "- " << endl;
                        cout << "artist" << setw(30) << "album" << setw(30) << "genre" << endl;
                        a++;
                    }
                    cout << filtered.artist[i] << setw(30) << filtered.album[i] << setw(30) << filtered.genre[i] << endl;
                }
                else
                {
                    getline(fin, trash, '\n');
                }
                i++;
            }
            if (notfound)
            {
                cout << "No results found" << endl;
            }
        }
        fin.close();

        break;
    case 3: //filter by album
        fin.open("dummy.csv");
        if (!fin)
        {
            cout << "file could not be opened" << endl;
        }
        else
        {
            cout << "Enter the name of the album:";
            cin >> search;
            cout << endl;
            while (!fin.eof())
            {
                getline(fin, temp.song[i], ',');
                getline(fin, read, ',');
                if (read == search)
                {

                    notfound = false;
                    filtered.song[i] = temp.song[i];
                    filtered.album[i] = read;
                    getline(fin, temp.artist[i], ',');
                    getline(fin, temp.genre[i], '\n');
                    filtered.artist[i] = temp.artist[i];
                    filtered.genre[i] = temp.genre[i];
                    if (a == 0)
                    {
                        cout << "Results for the album " << filtered.album[i] << "- " << endl;
                        a++;
                    }
                    cout << filtered.song[i] << endl;
                }
                else
                {
                    getline(fin, trash, '\n');
                }
                i++;
            }
            if (notfound)
            {
                cout << "No results found" << endl;
            }
        }
        fin.close();
        break;
    case 4: //filter by genre
        fin.open("dummy.csv");
        if (!fin)
        {
            cout << "file could not be opened" << endl;
        }
        else
        {
            cout << "Enter the genre you would like to search:";
            cin >> search;
            cout << endl;
            while (!fin.eof())
            {
                getline(fin, temp.song[i], ',');
                getline(fin, temp.album[i], ',');
                getline(fin, temp.artist[i], ',');
                getline(fin, read, '\n');
                if (read == search)
                {
                    notfound = false;
                    filtered.genre[i] = read;
                    filtered.song[i] = temp.song[i];
                    filtered.artist[i] = temp.artist[i];
                    filtered.album[i] = temp.album[i];
                    if (a == 0)
                    {
                        cout << "Results for the genre " << filtered.genre[i] << "- " << endl;
                        cout << "Song" << setw(30) << "artist" << endl;
                        a++;
                    }
                    cout << filtered.song[i] << setw(30) << filtered.artist[i] << endl;
                }
                else
                {
                    getline(fin, trash, '\n');
                }
                i++;
            }
            if (notfound)
            {
                cout << "No results found" << endl;
            }
        }
        fin.close();
        break;
    case 5:
        return;
        break;
    default:
        cout << "invalid input" << endl;
    }
    goto lbl2;
}

void play_playlist_menu()
{
lbl:
    int subchoice;
    cout << "Play playlist" << endl;
    cout << "1>Play from song" << endl;
    cout << "2>Shuffle play" << endl;
    cout << "3>Return to main menu" << endl;
    cout << "Enter your choice:";
    cin >> subchoice;
    cout << endl;
    switch (subchoice)
    {
    case 1: //subfunction1
        cout << "Play from song" << endl;
        break;
    case 2: //subfunction2
        cout << "Shuffle play" << endl;
        break;
    case 3:
        return;
        break;

    default:
        cout << "Invalid Input" << endl;
    }
    goto lbl;
}

void display_all_records()
{
    ifstream fin;
    fin.open("dummy.csv");
    bool notfound = true;
    if (!fin)
    {
        cout << "file could not be opened" << endl;
    }
    else
    {
        int i = 0;
        while (!fin.eof())
        {
            getline(fin, data.song[i], ',');
            getline(fin, data.album[i], ',');
            getline(fin, data.artist[i], ',');
            getline(fin, data.genre[i], '\n');
            i++;
            size++;
        }
    }
    fin.close();
    cout << "song" << setw(30) << "album" << setw(30) << "artist" << setw(30) << "genre" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << data.song[i] << setw(30) << data.album[i] << setw(30) << data.artist[i] << setw(30) << data.genre[i] << endl;
    }
}
