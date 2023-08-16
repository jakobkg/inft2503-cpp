template<typename T1, typename T2>
class Pair {
    public:
    T1 first;
    T2 second;

    Pair(T1, T2);

    bool operator>(Pair<T1, T2> const) const;
    Pair<T1, T2> operator+(const Pair<T1, T2> &other) const;
};

template <typename T1, typename T2>
Pair<T1, T2>::Pair(T1 first, T2 second) : first(first), second(second) {}

template <typename T1, typename T2>
Pair<T1, T2> Pair<T1, T2>::operator+(const Pair<T1, T2> &other) const {
  return Pair(first + other.first, second + other.second);
}

template <typename T1, typename T2>
bool Pair<T1, T2>::operator>(const Pair<T1, T2> other) const {
  return (this->first + this->second) > (other.first + other.second);
}
