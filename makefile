.SILENT:

COMP = g++ -Wall -I include/
crea = creation de

all:  Test10a

objs/MyQT.o: sources/MyQT.cpp include/MyQT.h  
	echo $(crea) MyQT.o
	$(COMP) sources/MyQT.cpp -c -o objs/MyQT.o  -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++

objs/ImageNG.o: sources/ImageNG.cpp include/ImageNG.h 
	echo $(crea) ImageNG.o
	$(COMP) sources/ImageNG.cpp -c -o objs/ImageNG.o  -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++
objs/Couleur.o: sources/Couleur.cpp include/Couleur.h 
	echo $(crea) Couleur.o
	$(COMP) sources/Couleur.cpp -c -o objs/Couleur.o -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++
objs/ImageRGB.o: sources/ImageRGB.cpp include/ImageRGB.h 
	echo $(crea) ImageRGB.o
	$(COMP) sources/ImageRGB.cpp -c -o objs/ImageRGB.o  -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++
objs/ImageB.o: sources/ImageB.cpp include/ImageB.h 
	echo $(crea) ImageB.o
	$(COMP) sources/ImageB.cpp -c -o objs/ImageB.o  -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++

objs/Exception.o: sources/Exception.cpp include/Exception.h 
	echo $(crea) Exception.o
	$(COMP) sources/Exception.cpp -c -o objs/Exception.o  -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++

objs/RGBException.o: sources/RGBException.cpp include/RGBException.h 
	echo $(crea) RGBException.o
	$(COMP) sources/RGBException.cpp -c -o objs/RGBException.o  -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++

objs/XYException.o: sources/XYException.cpp include/XYException.h 
	echo $(crea) XYException.o
	$(COMP) sources/XYException.cpp -c -o objs/XYException.o  -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++


objs/Dimension.o: sources/Dimension.cpp include/Dimension.h
	echo $(crea) Dimension.o
	$(COMP) sources/Dimension.cpp -c -o objs/Dimension.o -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++

objs/Image.o: sources/Image.cpp include/Image.h
	echo $(crea) Image.o
	$(COMP) sources/Image.cpp -c -o objs/Image.o -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++

objs/Iterateur.o: sources/Iterateur.cpp include/Iterateur.h
	echo $(crea) Iterateur.o
	$(COMP) sources/Iterateur.cpp -c -o objs/Iterateur.o -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++


objs/ArrayList.o: sources/ArrayList.cpp include/ArrayList.h
	echo $(crea) ArrayList.o
	$(COMP) sources/ArrayList.cpp -c -o objs/ArrayList.o -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++

objs/SortedArrayList.o: sources/SortedArrayList.cpp include/SortedArrayList.h
	echo $(crea) SortedArrayList.o
	$(COMP) sources/SortedArrayList.cpp -c -o objs/SortedArrayList.o -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++

objs/PhotoShop.o: sources/PhotoShop.cpp include/PhotoShop.h
	echo $(crea) PhotoShop.o
	$(COMP) sources/PhotoShop.cpp -c -o objs/PhotoShop.o -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++


objs/Traitements.o: sources/Traitements.cpp include/Traitements.h
	echo $(crea) Traitements.o
	$(COMP) sources/Traitements.cpp -c -o objs/Traitements.o -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++


Test10a: sources/Test10a.cpp objs/Exception.o objs/Traitements.o objs/PhotoShop.o objs/XYException.o objs/RGBException.o objs/ImageRGB.o objs/ImageB.o objs/ImageNG.o objs/Couleur.o objs/Dimension.o objs/MyQT.o objs/Image.o objs/Iterateur.o objs/ArrayList.o objs/SortedArrayList.o 
	echo $(crea) Test10a
	$(COMP) sources/Test10a.cpp objs/Exception.o objs/Traitements.o objs/PhotoShop.o objs/XYException.o objs/RGBException.o objs/ImageRGB.o objs/ImageB.o objs/ImageNG.o objs/Couleur.o objs/Dimension.o objs/MyQT.o objs/Image.o objs/Iterateur.o objs/ArrayList.o objs/SortedArrayList.o -o bin/Test10a -lQt5Widgets -lQt5Gui -lQt5Core -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore


clean:
	rm -f objs/*.o core

clobber: clean
	rm -f bin/Test10a
