JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
        Bigram.java \
	Pair.java \
        BigramMap.java \
	DynamicArray.java \
        BigramDyn.java \
        _mainTester.java 

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class
