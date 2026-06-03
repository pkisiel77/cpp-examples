#include <iostream>
#include <map>
#include <string>

class MovieLibrary
{
public:
    bool addMovie(const std::string& title, double rating)
    {
        if (rating < 1.0 || rating > 5.0)
        {
            return false;
        }

        if (movies.find(title) != movies.end())
        {
            return false;
        }

        movies[title] = rating;
        return true;
    }

    bool removeMovie(const std::string& title)
    {
        return movies.erase(title) > 0;
    }

    bool getRating(const std::string& title, double& rating) const
    {
        auto result = movies.find(title);
        if (result == movies.end())
        {
            return false;
        }

        rating = result->second;
        return true;
    }

    double getAverageRating() const
    {
        if (movies.empty())
        {
            return 0.0;
        }

        double sum = 0.0;
        for (const auto& movie : movies)
        {
            sum += movie.second;
        }

        return sum / movies.size();
    }

    std::string getHighestRatedMovie() const
    {
        if (movies.empty())
        {
            return "";
        }

        auto best = movies.begin();
        for (auto it = movies.begin(); it != movies.end(); ++it)
        {
            if (it->second > best->second)
            {
                best = it;
            }
        }

        return best->first;
    }

private:
    std::map<std::string, double> movies;
};

int main()
{
    MovieLibrary library;

    library.addMovie("Matrix", 5.0);
    library.addMovie("Incepcja", 4.8);
    library.addMovie("Interstellar", 4.9);

    double rating = 0.0;
    if (library.getRating("Matrix", rating))
    {
        std::cout << "Ocena Matrix: " << rating << std::endl;
    }

    std::cout << "Srednia ocena: " << library.getAverageRating() << std::endl;
    std::cout << "Najwyzej oceniony film: " << library.getHighestRatedMovie() << std::endl;

    library.removeMovie("Incepcja");
    std::cout << "Srednia po usunieciu: " << library.getAverageRating() << std::endl;

    return 0;
}
