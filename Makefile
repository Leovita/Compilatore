CXX = g++
CXXFLAGS = -Wall -w -std=c++17 -arch arm64
LDFLAGS = -arch arm64
FLEX = flex
BISON = bison

# Target principale
all: compiler

# Regola per compilare l'eseguibile finale
compiler: driver.o scanner.o parser.o main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Regola per compilare parser.cpp e parser.hpp da astparser.yy
parser.cpp parser.hpp: parser.yy
	$(BISON) -d -o parser.cpp parser.yy

# Regola per compilare scanner.cpp da astscanner.ll
scanner.cpp: scanner.ll parser.hpp
	$(FLEX) -o scanner.cpp scanner.ll

# Regola per compilare astdriver.o (assicurati che astparser.hpp esista prima di compilare)
driver.o: driver.cpp parser.hpp
	$(CXX) $(CXXFLAGS) -c driver.cpp

# Regola per compilare main.o
main.o: main.cpp driver.hpp parser.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Regola per compilare astparser.o
parser.o: parser.cpp parser.hpp
	$(CXX) $(CXXFLAGS) -c parser.cpp

# Pulizia dei file generati
clean:
	rm -f compiler parser.cpp parser.hpp scanner.cpp driver.o main.o parser.o *.o *.pdf *.tex *.log *.aux
