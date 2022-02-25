#include<iostream>
#include<list>
#include<string>
#include<cctype>
#include<iomanip>
#include<limits>

class Song{
    friend std::ostream &operator<<(std::ostream &os,const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        :name{name},artist{artist},rating{rating}{}
        
    std::string get_name()const{
        return name;
    }
    std::string get_artist()const{
        return artist;
    }
    int get_rating()const{
        return rating;
    }
    bool operator<(const Song &rhs)const{
        return this->name < rhs.name;
    }
    bool operator==(const Song &rhs)const{
        return this->name == rhs.name;
    }

};

std::ostream &operator<<(std::ostream &os,const Song &s){
    os << std::setw(20) << std::left << s.name
    << std::setw(30) << std::left << s.artist
    << std::setw(2) << std::left << s.rating;
    return os;
}

void display_menu(){
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next Song" << std::endl;
    std::cout << "P - Play Previous Song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List current playlist" << std::endl;
    std::cout << "======================================================" << std::endl;
    std::cout << "Enter a selection (Q to quit):" ;

}

void play_current_song(const Song &song){
    std::cout << "Now playing " << std::endl;
    std::cout << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist,const Song &current_song){
    for(const Song &song: playlist){
        std::cout << song << std::endl;
    }
    std::cout << "Current song" << std::endl;
    std::cout << current_song << std::endl;
}

int main(int argc, char const *argv[])
{
    std::list<Song> playlist{
        {"God's Plan",	"Drake", 		5},
        {"Never Be The Same",	"Camila Cabello", 		5},
        {"Pray For Me",	"The Weekend and K.Lamar", 		4},
        {"The Middle",	"Zedd,Maren Morris & Grey", 		5},
        {"Wait",	"Maroon 5", 		4},
        {"Whatever it Takes",	"Imagine Dragons", 		3},
        
    };

    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist,*current_song);

    char selection{};

    do{
        display_menu();
        std::cin >> selection;
        selection = std::toupper(selection);
        if(selection == 'F'){
            std::cout << "Playing first song" << std::endl;
            current_song = playlist.begin();
            play_current_song(*current_song);
        }
        else if(selection == 'N'){
            std::cout << "Playing next song" << std::endl;
            current_song++;
            if(current_song == playlist.end()){
                std::cout << "Wrapping to start of playlist" << std::endl;
                current_song = playlist.begin();
            }
            play_current_song(*current_song);
        }
        else if(selection == 'P'){
            std::cout << "Playing previous song" << std::endl;
            if(current_song == playlist.begin()){
                std::cout << "Wrapping to end of playlist" << std::endl;
                current_song = playlist.end();
            }
            current_song--;
            play_current_song(*current_song);
        }
        else if(selection == 'A'){
            std::string song_name;
            std::string song_artist;
            int song_rating; 
            std::cin.clear();   // To clear cin stream before use, keeps from executing immediately without user input
            std::cin.ignore();  // To ignore garbage trailing data after each input ex. '\n'

            std::cout << "Adding and playing new song" << std::endl;
            std::cout << "Enter a song: ";
            std::getline(std::cin,song_name);

            std::cout << "Who is the artist of the song? " << std::endl;
            std::getline(std::cin,song_artist);

            std::cout << "What is your personal rating for the song? (1-5 max): " << std::endl; 
            std::cin >> song_rating;
            std::cin.ignore();
            
            
            playlist.insert(current_song,Song{song_name,song_artist,song_rating});
            current_song--;
            play_current_song(*current_song);
            
        }else if(selection == 'L'){
            std::cout << std::endl;
            display_playlist(playlist,*current_song);

        }else if(selection == 'Q')
            std::cout << "Quitting" << std::endl;

        else
            std::cout << "Sorry that is not a invalid choice" << std::endl;
    
    }while(selection != 'Q');
        std::cout << "Thanks for listening!" << std::endl;
    
    return 0;
}
