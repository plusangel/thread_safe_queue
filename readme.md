# Thread safe queue wrapper

This is a thread-safe queue class. We use a std::queue internally to store elements.
We experiment with lock guards, mutexes and condition variables. 
We test it using Josh's Lospinoso goat rodeo example (by the way, C++ crash course is a great book).

### maintainer
angelos plastropoulos