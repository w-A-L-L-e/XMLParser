CC	= g++

#nu gaan we voor elke .o file compileren met g++ -c .cpp
%.o:%.cpp
	$(CC) -c -O2 $^ 



all: xml ntree




xml: XMLParser.cpp XMLLexer.cpp ntree main.o XMLParser.o XMLLexer.o \
xmlnode.o elementnode.o textnode.o attribute.o commentnode.o\
pinode.o
	g++ -o xml -O2 main.o XMLParser.o XMLLexer.o \
xmlnode.o elementnode.o textnode.o attribute.o commentnode.o\
pinode.o -lfl

XMLParser.cpp: xml.yacc XMLParseFunctions.h
	bison++ -d xml.yacc -h XMLParser.h -o XMLParser.cpp

XMLLexer.cpp: xml.lex
	flex++ -oXMLLexer.cpp xml.lex



run: test.xml
	cat test.xml
	./xml test.xml


ntree: xmlnode.h xmlnode.o ntree.cpp
	g++ -o ntree -O2  ntree.cpp xmlnode.o

clean: 
	rm -f *.o xml *~ core XMLLexer.cpp \
XMLParser.h XMLParser.cpp ntree

