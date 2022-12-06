class Rectangle { 

public:	 

	Rectangle (int length = 0, int width = 0) : m_length( length ), 
						    m_width(width) {}; 
	int get_length() { return m_length; } 
	int get_width() { return m_width; } 
	void set_length(int length) { m_length = length; } 
	void set_width(int width) { m_width = width; } 
	int perimeter(){ return 2 * (m_length + m_width); }	 

private: 
	int m_length; 
	int m_width;	 
};

int main(){

}
