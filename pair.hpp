namespace stl {
    template<typename T1, typename T2>
    class pair {
    public:
        T1 first;
        T2 second;
        pair(T1, T2);
        bool operator<(const pair<T1, T2>&) const;
    };

    template<typename T1, typename T2>
    pair<T1, T2>::pair(T1 f, T2 s) {
        this->first = f;
        this->second = s;
    }

    template<typename T1, typename T2>
    bool pair<T1, T2>::operator<(const pair<T1, T2> &other) const {
        return (this->first == other.first) ? (this->second < other.second) : (this->first < other.first);
    }

    template<typename T1, typename T2>
    pair<T1, T2> make_pair(T1 f, T2 s) {
        return pair<T1, T2>(f, s);
    }
}
