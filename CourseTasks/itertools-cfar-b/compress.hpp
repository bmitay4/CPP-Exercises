namespace itertools {
class compress {
   private:
    int _start, _last;

   public:
    //Constructors
    template <class T>
    compress(T) {
    }
    template <class T, typename Function>
    compress(T, Function) {
    }

    //public iterator
    class iterator {
        int current;

       public:
        iterator(int value = 0) : current(value) {}

        //Increment
        iterator &operator++() {
            current = current + 1;
            return *this;
        }
        const iterator operator++(int) {
            iterator temp = *this;
            current = current + 1;
            return temp;
        }
        //Decrement
        iterator &operator--() {
            current = current - 1;
            return *this;
        }
        const iterator operator--(int) {
            iterator temp = *this;
            current = current - 1;
            return temp;
        }
        bool operator==(const iterator &it) const {
            return current == it.current;
        }

        bool operator!=(const iterator &it) const {
            return current != it.current;
        }

        int operator*() {
            return current;
        }
    };
    iterator begin() {
        return iterator(2);
    }
    iterator end() {
        return iterator(2);
    }
};
}  // namespace itertools