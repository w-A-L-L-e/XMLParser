First install bison++.
You need a patched bison++ and latest flex for this to build on gcc 4.2+. This uses the flex++ and bison++ features to generate classes. 
The bison++ with patches will be uploaded in another git repo soon...

Then run make.
You can now test the parser by running 
./xml test.xml

In main.cpp you can see how the XMLParser is used.
