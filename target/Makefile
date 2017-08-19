# Directories
EXEC=target_selection
SRCDIR=src
IDIR=include ../include
OBJDIR=obj
BINDIR=bin
LIBDIR=../lib

# Compiler flags
IDIRFLAGS=$(foreach idir, $(IDIR), -I$(idir))
CXXFIRSTFLAGS= -O2 -DNDEBUG -W -Wall -Wextra -pedantic -Wno-sign-compare -Wno-unused-parameter $(IDIRFLAGS)

# Compiler
ifneq (,$(findstring g++,$(CXX)))
	CXXFLAGS= -std=c++14 $(CXXFIRSTFLAGS)
else
	CXXFLAGS= -std=c++1y -stdlib=libc++ $(CXXFIRSTFLAGS)
endif


# Linker flags
LDFLAGS=-L$(LIBDIR) -pthread -l:libghost.so

# Files
SOURCES=$(foreach sdir, $(SRCDIR), $(wildcard $(sdir)/*.cpp))
OBJECTS=$(patsubst %.cpp, $(OBJDIR)/%.o, $(notdir $(SOURCES)))

# For rm
SOURCESTILDE=$(foreach sdir, $(SRCDIR), $(wildcard $(sdir)/*.cpp~))
INCLUDESTILDE=$(foreach idir, $(IDIR), $(wildcard $(idir)/*.hpp~))

vpath %.cpp $(SRCDIR)

# Reminder, 'cause it is easy to forget makefile's fucked-up syntax...
# $@ is what triggered the rule, ie the target before :
# $^ is the whole dependencies list, ie everything after :
# $< is the first item in the dependencies list

# Rules
all: $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean 

clean:
	rm -fr core *~ $(EXEC) $(OBJECTS) $(SOURCESTILDE) $(INCLUDESTILDE)
