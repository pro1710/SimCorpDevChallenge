CXX=g++
RM=rm -f

CPPFLAGS=-g --std=c++11 -Wall -pedantic

SRCDIR=src

SRCS=$(SRCDIR)/main.cpp \
	 $(SRCDIR)/TripletZeroSum/TripletZeroSum.cpp

OBJS=$(subst .cpp,.o,$(SRCS))

TARGET=solver.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS) 

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) *~ .depend

doc:
	doxygen Doxyfile

include .depend
