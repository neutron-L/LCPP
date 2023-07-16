IDIR = include
LDIR = lib
ODIR = obj
SRC = src
BIN = bin
objects := $(patsubst ${LDIR}/%.cc,${ODIR}/%.o,$(wildcard ${LDIR}/*.cc))
PROGRAM = test_blob test_text test_ptr test_mail test_vec test_str \
	test_quote test_basket test_query test_complex test_stack test_student \
	test_template

all: $(PROGRAM)

CXX = g++
CFLAGS = -I$(IDIR) -Og -g -Wall -std=c++11

test_blob: $(SRC)/test_blob.cc $(ODIR)/blob.o $(IDIR)/blob.hh
	$(CXX) $(CFLAGS) -o $(BIN)/$@ $^

test_text: $(SRC)/test_text.cc $(ODIR)/text.o $(IDIR)/text.hh
	$(CXX) $(CFLAGS) -o $(BIN)/$@ $^

test_ptr: $(SRC)/test_ptr.cc $(ODIR)/ptr.o $(IDIR)/ptr.hh
	$(CXX) $(CFLAGS) -o $(BIN)/$@ $^

test_mail: $(SRC)/test_mail.cc $(ODIR)/mail.o $(IDIR)/mail.hh
	$(CXX) $(CFLAGS) -o $(BIN)/$@ $^

test_vec: $(SRC)/test_vec.cc $(ODIR)/strvec.o $(IDIR)/strvec.hh
	$(CXX) $(CFLAGS) -o $(BIN)/$@ $^

test_str: $(SRC)/test_str.cc $(ODIR)/string.o $(IDIR)/string.hh
	$(CXX) $(CFLAGS) -o $(BIN)/$@ $^

test_quote: $(SRC)/test_quote.cc $(ODIR)/quote.o $(IDIR)/quote.hh
	$(CXX) $(CFLAGS) -o $(BIN)/$@ $^

test_basket: $(SRC)/test_basket.cc $(ODIR)/basket.o $(IDIR)/basket.hh
	$(CXX) $(CFLAGS) -o $(BIN)/$@ $^

test_query: $(SRC)/test_query.cc $(ODIR)/query.o $(IDIR)/query.hh
	$(CXX) $(CFLAGS) -o $(BIN)/$@ $^

test_complex: $(SRC)/test_complex.cc $(ODIR)/complex.o $(IDIR)/complex.hh
	$(CXX) $(CFLAGS) -o $(BIN)/$@ $^

test_stack: $(SRC)/test_stack.cc $(ODIR)/stack.o $(IDIR)/stack.hh
	$(CXX) $(CFLAGS) -o $(BIN)/$@ $^

test_student: $(SRC)/test_student.cc $(ODIR)/studenti.o $(IDIR)/studenti.hh
	$(CXX) $(CFLAGS) -o $(BIN)/$@ $^

test_template: $(SRC)/test_template.cc $(IDIR)/template.hh
	$(CXX) $(CFLAGS) -o $(BIN)/$@ $^

$(ODIR)/%.o: $(LDIR)/%.cc $(IDIR)/%.hh
	$(CXX) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	-rm $(BIN)/*
	-rm $(objects) 