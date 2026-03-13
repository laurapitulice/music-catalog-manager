# 🎶 "Music Playlist Manager" - Command-line application in C++
A project I made while practicing data structures in C++. The idea behind this program is to manage a collection of songs similar to a database.

## 🚀 Features
- Custom Data Structure: Uses a nested struct to store song titles, artists, and duration (minutes/seconds).
- Data Management: Input multiple songs and store them in a list.
- File Export: Save your entire playlist to an external .out file.
- Search: Filter and display songs by a specific artist.
- Sorting: Automatically sort the playlist alphabetically by song title.
- Duration Calculator: Calculates the total playback time of the entire playlist in _HH:MM:SS_ format.

## 📂 How to use
1. Download zip code and unzip file to the desired path
2. Open folder main.cpp` in VSCode
3. **Configure the compiler ("g++.exe"):**
    - in `tasks.json`: make sure the compiler used is `"g++.exe"`
    - (optional: open in windows console) in `launch.json`: set `"externalConsole": true`
4. Run the executable & navigate using the menu:
    - 1: Input song details.
    - 2: Display all songs.
    - 3: Sort songs alphabetically by title.
    - 4: Export data to iesire.out.
    - 5: View total playlist duration.
    - 6: Search for songs by artist.
    - 0: Exit.
