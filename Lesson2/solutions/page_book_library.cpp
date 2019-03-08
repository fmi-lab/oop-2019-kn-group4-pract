#include <iostream>
#include <cstring>
using namespace std;

class Page
{
	unsigned int pageNumber;
	char text[255];
public:
	Page()
	{
		this->pageNumber = 0;
		
		this->text[0] = '\0';
	}
	Page(const Page & otherPage)
	{
		this->pageNumber = otherPage.pageNumber;
		
		strcpy(this->text, otherPage.text);
	}
	
	// GET-ters
	unsigned int getPageNumber() const
	{
		return this->pageNumber;
	}
	void getText(char * returnText) const
	{
		strcpy(returnText, this->text);
	}
	
	// SET-ters
	void setPageNumber(int newPageNumber)
	{
		this->pageNumber = newPageNumber;
	}
	void setText(const char * newText)
	{
		strcpy(this->text, newText);
	}
	
	// compare pages by page number
	int pagecmp(const Page & otherPage)
	{
		if(this->pageNumber < otherPage.pageNumber) return -1;
		if(this->pageNumber > otherPage.pageNumber) return 1;
		return 0;
	}
};

class Book
{
	char title[32];
	Page pages[16];
	
	size_t numberOfPages;
public:
	Book()
	{
		this->title[0] = '\0';
		numberOfPages = 0;
	}
	
	/// GET-ters
	Page getPage(size_t pageNumber) const
	{
		return this->pages[pageNumber];
	}
	void getTitle(char * returnTitle) const 
	{
		strcpy(returnTitle, this->title);
	}
	size_t getSize() const
	{
		return this->numberOfPages;
	}
	
	/// SET-ters
	void setPage(size_t pageNumber, const Page & page)
	{
		this->pages[pageNumber].setPageNumber(page.getPageNumber());
		
		char text[255];
		page.getText(text);
		
		this->pages[pageNumber].setText(text);
	}
	void setTitle(char * newTitle)
	{
		strcpy(this->title, newTitle);
	}
};

class Library
{
	Book books[4];
	size_t numberOfBooks;
public:
	Book()
	{
		this->numberOfBooks = 0;
	}
	
	/// GET-ters
	size_t getSize() const
	{
		return this->numberOfBooks;
	}
	Book getBook(size_t numberOfBook) const
	{
		return this->books[numberOfBook];
	}
	
	/// SET-ters
	void setBook(size_t bookNumber, const Book & newBook)
	{
		char title[32];
		newBook.getTitle(title);
		this->book[bookNumber].setTitle(title);
		
	}
}

int main()
{
	return 0;
}