from random import shuffle
from typing import Optional


class Song:
    """Represents a music track with title, artist, and duration."""

    def __init__(self, title: str, artist: str, duration: int):
        self.title = title
        self.artist = artist
        self.duration = duration

    @property
    def title(self) -> str:
        return self._title

    @title.setter
    def title(self, title: str):
        if not isinstance(title, str) or not title.strip():
            raise ValueError("Title can't be empty")
        self._title = title.strip()

    @property
    def artist(self) -> str:
        return self._artist

    @artist.setter
    def artist(self, artist: str):
        if not isinstance(artist, str) or not artist.strip():
            raise ValueError("Artist can't be empty")
        self._artist = artist.strip()

    @property
    def duration(self) -> int:
        return self._duration

    @duration.setter
    def duration(self, duration: int):
        if not isinstance(duration, int) or duration <= 0:
            raise ValueError("Duration must be a positive integer")
        self._duration = duration

    def __str__(self) -> str:
        return f"Music '{self.title.title()}' by {self.artist.title()} ({self.duration}s)"

    @classmethod
    def from_string(cls, data: str) -> "Song":
        """Create a Song from a string in the format: 'Title - Artist - Duration'"""
        try:
            title, artist, duration_str = data.strip().split(" - ")
            duration = int(duration_str)
            return cls(title, artist, duration)
        except (ValueError, TypeError):
            raise ValueError("Invalid format. Use: 'Title - Artist - Duration'")


class Playlist:
    """Represents a collection of songs."""

    def __init__(self, name: str):
        self.name = name
        self._songs: list[Song] = []

    @property
    def name(self) -> str:
        return self._name

    @name.setter
    def name(self, name: str):
        if not isinstance(name, str) or not name.strip():
            raise ValueError("Playlist name can't be empty")
        self._name = name.strip()

    @property
    def total_duration(self) -> int:
        """Returns the total duration of the playlist in minutes."""
        if not self._songs:
            return 0
        total_seconds = sum(song.duration for song in self._songs)
        return total_seconds // 60

    @property
    def total_songs(self) -> int:
        """Returns the number of songs in the playlist."""
        return len(self._songs)

    def add_song(self, song: Song) -> None:
        """Add a song to the playlist."""
        self._songs.append(song)

    def remove_song(self, title: str) -> None:
        """Remove a song by its title (case insensitive)."""
        for song in self._songs:
            if song.title.lower() == title.lower():
                self._songs.remove(song)
                return
        raise ValueError(f"Song '{title}' not found in playlist")

    def find_song(self, title: str) -> Optional[Song]:
        """Find and return a song by title. Returns None if not found."""
        for song in self._songs:
            if song.title.lower() == title.lower():
                return song
        return None

    def list_songs(self) -> list[Song]:
        """Return the list of all songs in the playlist."""
        return self._songs

    def shuffle(self) -> None:
        """Shuffle the songs in the playlist."""
        shuffle(self._songs)

    @classmethod
    def from_songs(cls, name: str, songs: list[Song]) -> "Playlist":
        """Create a Playlist pre-populated with a list of songs."""
        playlist = cls(name)
        for song in songs:
            playlist.add_song(song)
        return playlist

    @classmethod
    def empty(cls, name: str) -> "Playlist":
        """Create an empty playlist."""
        return cls(name)

    def __str__(self) -> str:
        return f"Playlist '{self.name}': {self.total_songs} songs, {self.total_duration} minutes total"


# ==================== TESTS ====================

if __name__ == "__main__":
    print("=== Creating Songs ===")
    song1 = Song("Bohemian Rhapsody", "Queen", 354)
    song2 = Song("Hotel California", "Eagles", 391)
    song3 = Song.from_string("Stairway to Heaven - Led Zeppelin - 482")

    print(song1)
    print(song2)
    print(song3)

    print("\n=== Creating Playlist ===")
    playlist = Playlist("Rock Classics")
    playlist.add_song(song1)
    playlist.add_song(song2)
    playlist.add_song(song3)

    print(playlist)
    print("Total duration:", playlist.total_duration, "minutes")

    print("\n=== Listing Songs ===")
    for song in playlist.list_songs():
        print("-", song)

    print("\n=== Finding a Song ===")
    found = playlist.find_song("Hotel California")
    print(found)

    print("\n=== Removing a Song ===")
    playlist.remove_song("Bohemian Rhapsody")
    print(playlist)

    print("\n=== Using Class Methods ===")
    playlist2 = Playlist.from_songs("My Top 2", [song2, song3])
    print(playlist2)

    playlist3 = Playlist.empty("Empty Playlist")
    print(playlist3)

    print("\n=== Testing Validations ===")
    try:
        Song("", "Queen", 300)
    except ValueError as e:
        print("Expected error:", e)

    try:
        Song("Test", "Artist", -10)
    except ValueError as e:
        print("Expected error:", e)

    try:
        playlist.remove_song("Nonexistent Song")
    except ValueError as e:
        print("Expected error:", e)