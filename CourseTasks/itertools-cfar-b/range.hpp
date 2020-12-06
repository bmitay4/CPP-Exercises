namespace itertools {
class range {
   private:
    int start;
    int last;

   public:
    //Constructor
    range(int a, int b) : start(a), last(b) {}

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
        return iterator(start);
    }
    iterator end() {
        return iterator(last);
    }
};
}  // namespace itertools