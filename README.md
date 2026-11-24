# THE SCP WIKI ARCHIVES
<img alt="GitHub License" src="https://img.shields.io/github/license/dascomrade/scpwiki-local?style=for-the-badge">
<img alt="Maintained?" src="https://img.shields.io/badge/Maintained%3F-YES-green?style=for-the-badge"> 

**a locally run version of the SCP Wiki. With a consistent design across all\* articles**


  <sub> *anomalies like  2521, and 001 due to the nature of their articles have "Unique" articles rather than just loading a JSON to the template page </sub>

This was made when I realized just how different the different articles of the SCP wiki are, and that much of the language is unexplained like "Keter" or even more-so "Keneq" and "Vlam" along with "Esoteric" ones and most people assume that "Safe" means harmless and "Keter" means extremely violent, which as the ACS says, is not the case (its not about danger its about contain-ability), so I wanted to make my own version of it, and because I did not want to spend money on domain name I chose to make it a desktop app, and wrote it in C and GTK due to the known RAM inefficiency of web-apps. Plus by storing the Anomalies in JSON files developers are able to very easily grab parts of the data they want while in the earlier (the most popular articles) the data is in unlabeled divs

- [x] Start Page UI
- [x] Input Handling & Validation 
- [ ] Database searching
- [ ] Database modification by End-User
- [ ] Loading results on Result Page
- [ ] Opening Article Window
- [ ] Unique Anomalies

## Building

**external libraries that are needed are as follows:**

- GTK 3 
- cJSON 
- SQLite3

**ArchLinux**
`sudo pacman -S --needed gtk3 cjson sqlite`

**Debian/Ubuntu/Pop!_OS**
`sudo apt install libgtk-3-dev libcjson-dev libsqlite3-dev`

**RHEL/Fedora**
` sudo dnf install gtk3-devel cjson-devel sqlite sqlite-devel`

**LFS**
- GTK 3 https://download.gnome.org/sources/gtk/3.24/ </li>
- cJSON https://github.com/DaveGamble/cJSON </li>
- SQLite3 https://sqlite.org/?download.html</li>

**Once dependencies are installed,** `cd` **to** `scpwiki-local/frontend/` **and run** `make`
**you can run the program with** `./"The SCP Wiki"`
