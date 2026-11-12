# python_movie_milestone
# The movie collection starts as a list of dictionaries
movie_collection = [
    {"title": "how to loose a guy in 10 days", "director": "Donald Petrie", "year": "2003", "genre": "rom-com"},
    {"title": "10 things i hate about you", "director": "Gill junger", "year": "1999", "genre": "rom-com"},
    {"title": "notting hill", "director": "Roger Michell", "year": "1999", "genre": "rom-com"}
]

def add_movie():
    """Feature 1: Adds a new movie to the collection."""
    print("\n--- Add a New Movie ---")
    title = input("Enter movie title: ").strip()
    director = input("Enter director name: ").strip()
    year = input("Enter release year: ").strip()
    genre = input("Enter genre: ").strip()
    
   
    new_movie = {"title": title, "director": director, "year": year, "genre": genre}
    movie_collection.append(new_movie)
    print(f"Successfully added '{title}' to your collection.")

def view_movies():
    """Feature 2: Displays all movies in the collection."""
    print("\n--- Your Movie Collection ---")
    if not movie_collection:
        print("Your collection is currently empty.")
        return
        
    for index, movie in enumerate(movie_collection, 1):
        print(f"{index}. {movie['title']} | Director: {movie['director']} | Year: {movie['year']} | Genre: {movie['genre']}")

def find_movie():
    """Feature 3: Finds movies matching a specific attribute."""
    print("\n--- Find a Movie ---")
    print("Search by: 1. Title | 2. Director | 3. Year | 4. Genre")
    choice = input("Select a search attribute (1-4): ").strip()
    
    if choice == "1":
        attribute = "title"
    elif choice == "2":
        attribute = "director"
    elif choice == "3":
        attribute = "year"
    elif choice == "4":
        attribute = "genre"
    else:
        print("Error: Invalid search choice.")
        return

    search_query = input(f"Enter the {attribute} to search for: ").strip().lower()
    
   
    results = [movie for movie in movie_collection if search_query in movie[attribute].lower()]
    
    print(f"\n--- Search Results ({len(results)} found) ---")
    if results:
        for movie in results:
            print(f"Title: {movie['title']} ({movie['year']}) - Directed by {movie['director']} [{movie['genre']}]")
    else:
        print("No matching movies found.")

def main_menu():
    """Main application loop and menu control."""
    while True:
        print("\n==============================")
        print("      MOVIE STORAGE APP       ")
        print("==============================")
        print("1. Add a new movie")
        print("2. View all movies")
        print("3. Find a movie")
        print("4. Exit application")
        
        user_choice = input("Choose an option (1-4): ").strip()
        
        if user_choice == "1":
            add_movie()
        elif user_choice == "2":
            view_movies()
        elif user_choice == "3":
            find_movie()
        elif user_choice == "4":
            print("Goodbye! Thanks for using Movie Storage.")
            break
        else:
            print("Error: Invalid selection. Please enter a number from 1 to 4.")

if __name__ == "__main__":
    main_menu()
