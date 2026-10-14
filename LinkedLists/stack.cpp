#include "stack.h"
#include"LinkedLists.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

void Stack::Push(const std::string& data, int line) {
	StackNode* newNode = new StackNode(data, line);
	newNode->next = top;
	top = newNode;
}

std::string Stack::Pop() {
	if (IsEmpty())
		return "";

	StackNode* toBeDeleted = top;
	std::string value = toBeDeleted->data;
	top = top->next;
	delete toBeDeleted;
	return value;
}

int Stack::Topline() {
	if (IsEmpty())
		return 0;

	return top->line;
}

std::string CleanTag(std::string tag) {
	std::size_t space = tag.find(' ');

	//remove the space
	if (space != std::string::npos) {
		tag = tag.substr(0, space);
	}

	//remove the '/' int the end of self closing tag
	if (!tag.empty() && tag.back() == '/')
		tag.pop_back();

	//lower register for tag
	for (char& c : tag)
		c = std::tolower(c);

	return tag;
}

bool IsVoidElement(const std::string& tag)
{
	static const std::string voidTags[] = {
		"area", "base", "br", "col", "embed", "hr", "img",
		"input", "link", "meta", "source", "track", "wbr"
	};

	for (const std::string& v : voidTags)
		if (tag == v)
			return true;

	return false;
}

int main() {

	std::ifstream inf{ "webpage1.html" };

	int lineNumber = 0;

	if (!inf) {
		std::cerr << "webpage1.html could not be opened for reading!\n";
		return 1;
	}

	std::string strInput{};

	Stack stack;

	while (std::getline(inf, strInput)) {
		std::size_t pos{ 0 };
		++lineNumber;

		while ((pos = strInput.find('<', pos)) != std::string::npos) {
			std::size_t end = strInput.find('>', pos);

			if (end == std::string::npos)
				break;

			std::string tag = strInput.substr(pos + 1, end - pos - 1);

			bool isClosing = (!tag.empty() && tag[0] == '/');
			bool isSelfClosing = (!tag.empty() && tag.back() == '/');

			if (isClosing)
				tag = tag.substr(1);

			tag = CleanTag(tag);

			if (tag.empty()) {
			}
			else if (isClosing) {
				if (stack.IsEmpty()) {
					std::cout << "ERROR: closing tag </" << tag << "> with nothing open\n";
				}
				else {
					int openLine = stack.Topline();
					std::string opened = stack.Pop();
					if (opened != tag) {
						std::cout << "ERROR at line " << lineNumber
							<< ": expected </" << opened << "> (opened at line " << openLine
							<< ") but found </" << tag << ">\n";
					}
				}
			}

			else if (isSelfClosing) {
			}


			else {
				if (!IsVoidElement(tag))
					stack.Push(tag, lineNumber);
			}

			pos = end + 1;
		}
	}

	while (!stack.IsEmpty()) {
		int line = stack.Topline();
		std::cout << "ERROR: tag <" << stack.Pop() << "> opened at line " << line << " was never closed\n";
	}

	return 0;
}
