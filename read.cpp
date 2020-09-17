#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> readfile(std::string filename, std::string search);
int main()
{
    std::string s;
    std::cout << "Enter the id - ";
    std::cin >> s;
    std::vector<std::string> data = readfile("dummy.csv", s);
    return 0;
}

std::vector<std::string> readfile(std::string filename, std::string search)
{
    std::vector<std::string> record;
    std::ifstream file;
    file.open(filename);
    bool found_record = false;
    std::string id;
    std::string artist;
    std::string album;
    std::string song;
    std::string genre;

    while (getline(file, id, ',') && !found_record)
    {
        getline(file, artist, ',');
        getline(file, album, ',');
        getline(file, song, ',');
        getline(file, genre, '\n');
        if (id == search)
        {
            found_record = true;
            record.push_back(id);
            record.push_back(artist);
            record.push_back(album);
            record.push_back(song);
            record.push_back(genre);
        }
    }

    if (found_record == true)
    {
        std::cout << "id- " << id;
        std::cout << "\n";
        std::cout << "artist- " << artist;
        std::cout << "\n";
        std::cout << "album- " << album;
        std::cout << "\n";
        std::cout << "song- " << song;
        std::cout << "\n";
        std::cout << "genre- " << genre;
    }
    else
    {
        std::cout << "No record found";
    }

    return record;
}