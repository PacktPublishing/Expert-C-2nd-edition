template <class T>
class V {
public:
    V( int n = 0) : m_nEle(n), m_buf(0) { creatBuf();}
    ~V(){ deleteBuf(); }
    V& operator = (const V &rhs) { /* ... */}
    V& operator = (const V &rhs) { /* ... */}
    T getMax(){ /* ... */ }
protected:
    void creatBuf() { /* ... */}
    void deleteBuf(){ /* ... */}
protected:
    int m_nEle;
    T * m_buf;
}; 