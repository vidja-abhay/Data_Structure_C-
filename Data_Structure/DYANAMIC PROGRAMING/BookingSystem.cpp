#include <iostream>
#include <string>
#include <vector>
#include <ctime> // Include ctime for time-related functions

using namespace std;

class Movie {
private:
    string title;
    string genre;
    int price;
    int duration; // in minutes
    string director;
    string cast;
    string releaseDate;
    int avgRating;

public:
    // Constructor
    Movie(string t, string g, int p, int d, string dir, string c, string rDate, int aRating) {
        this->title = t;
        this->genre = g;
        this->price = p;
        this->duration = d;
        this->director = dir;
        this->cast = c;
        this->releaseDate = rDate;
        this->avgRating = aRating;
    }

    // Getter methods
    string getTitle() const { return title; }
    string getGenre() const { return genre; }
    int getPrice() const { return price; }
    int getDuration() const { return duration; }
    string getDirector() const { return director; }
    string getCast() const { return cast; }
    string getReleaseDate() const { return releaseDate; }
    int getAgeRating() const { return avgRating; }

    // Method to display movie details
    void displayDetails() const {
        cout << "Title: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << "Price: " << price << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Director: " << director << endl;
        cout << "Cast: " << cast << endl;
        cout << "Release Date: " << releaseDate << endl;
        cout << "Age Rating: " << avgRating << "+" << endl;
    }
};

class Movies {
private:
    vector<Movie> movieList;

public:
    void addMovie(const Movie &movie) {
        movieList.push_back(movie);
    }

    void displayAllMovies() const {
        for (int i = 0; i < movieList.size(); ++i) {
            cout << "Movie " << i + 1 << " Details:" << endl;
            movieList[i].displayDetails();
            cout << "-------------------------" << endl;
        }
    }

    void searchMovie(const string& title) const {
        bool found = false;

        for(auto movie : movieList){
            if(movie.getTitle() == title){
                movie.displayDetails();
                found = true;
                break;
            }
        }

        if(!found){
            cout << "Movie titled '" << title << "' not found!" << endl;
        }
    }
};

class Booking {
private:
    class BookingDetail {
    public:
        Movie movie;
        string customerName;
        int seatRow;
        int seatCol;
        time_t bookingTime;

        // Constructor for BookingDetail
        BookingDetail(const Movie &m, const string &name, int row, int col, time_t time)
            : movie(m), customerName(name), seatRow(row), seatCol(col), bookingTime(time) {}
    };

    vector<BookingDetail> bookings;
    int seatAvailability[5][5]; // Example 5x5 seating arrangement

public:
    // Constructor to initialize seat availability
    Booking() {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                seatAvailability[i][j] = 0; // 0 means seat is available
            }
        }
    }

    // Method to create a booking
    void createBooking(const Movie &movie, const string &customerName, int seatRow, int seatCol) {
        if (seatAvailability[seatRow][seatCol] == 1) {
            cout << "Seat is already booked. Please select another seat." << endl;
            return;
        }

        BookingDetail newBooking(movie, customerName, seatRow, seatCol, time(0));
        bookings.push_back(newBooking);
        seatAvailability[seatRow][seatCol] = 1; // Mark seat as booked

        cout << "Booking successful for " << customerName << "!" << endl;
    }

    // Method to cancel a booking within a certain time period (e.g., 24 hours)
    void cancelBooking(const string &customerName, const Movie &movie) {
        time_t currentTime = time(0);
        bool found = false;

        for (auto it = bookings.begin(); it != bookings.end(); ++it) {
            if (it->customerName == customerName && it->movie.getTitle() == movie.getTitle()) {
                double hoursSinceBooking = difftime(currentTime, it->bookingTime) / 3600;

                if (hoursSinceBooking <= 24) { // Allow cancellation within 24 hours
                    seatAvailability[it->seatRow][it->seatCol] = 0; // Free up the seat
                    bookings.erase(it);
                    cout << "Booking canceled successfully for " << customerName << "." << endl;
                } else {
                    cout << "Cannot cancel booking. Time limit exceeded." << endl;
                }
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Booking not found for " << customerName << "." << endl;
        }
    }

    // Method to display all bookings
    void allBookings() const {
        if (bookings.empty()) {
            cout << "No bookings available." << endl;
            return;
        }

        for (size_t i = 0; i < bookings.size(); ++i) {
            cout << "Booking " << i + 1 << " Details:" << endl;
            cout << "Customer Name: " << bookings[i].customerName << endl;
            cout << "Movie Title: " << bookings[i].movie.getTitle() << endl;
            cout << "Seat: Row " << bookings[i].seatRow << ", Col " << bookings[i].seatCol << endl;
            cout << "Booking Time: " << ctime(&bookings[i].bookingTime);
            cout << "-------------------------" << endl;
        }
    }
};

int main() {
    Movies moviesCollection;
    Booking bookingSystem;

    Movie movie1("Inception", "Sci-Fi", 300, 148, "Christopher Nolan", "Leonardo DiCaprio, Joseph Gordon-Levitt", "16 July 2010", 13);
    Movie movie2("The Dark Knight", "Action", 400, 152, "Christopher Nolan", "Christian Bale, Heath Ledger", "18 July 2008", 13);

    moviesCollection.addMovie(movie1);
    moviesCollection.addMovie(movie2);

    cout << "All Movies:" << endl;
    moviesCollection.displayAllMovies();

    cout << "\nSearching for 'Inception':" << endl;
    moviesCollection.searchMovie("Inception");

    cout << "\nSearching for 'Avatar':" << endl;
    moviesCollection.searchMovie("Avatar");

    // Create bookings
    bookingSystem.createBooking(movie1, "Alice", 2, 3);
    bookingSystem.createBooking(movie2, "Bob", 1, 1);

    // Display all bookings
    cout << "\nAll Bookings:" << endl;
    bookingSystem.allBookings();

    // Attempt to cancel a booking
    cout << "\nAttempting to cancel Alice's booking for Inception:" << endl;
    bookingSystem.cancelBooking("Alice", movie1);

    // Display all bookings after cancellation
    cout << "\nAll Bookings after cancellation:" << endl;
    bookingSystem.allBookings();

    return 0;
}
