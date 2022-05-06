#################################################################
# 
# file: MyWidget.py 
#       defines a demo widget derived from QWidget
# 
# author: Peter Mackenzie-Helnwein
# created: 08-01-2010
# 
#################################################################

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import ( 
    QApplication, QMainWindow,
    QWidget, QLabel, QLineEdit, QPushButton,
    QVBoxLayout, QHBoxLayout
)

class MyWidget(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.initUI()
        
    def initUI(self):
        self.resize(400,120)
        
        # the vertical layout
        lyt=QVBoxLayout(self)
        title = QLabel("Simple button test with callback",self)
        title.setStyleSheet("color: red; font: 20pt bold")
        lyt.addWidget(title)
        
        # create a horizontal layout for a single line
        hbox = QHBoxLayout()   # note: no self for it must not take the Widget size
        hbox.addWidget(QLabel("Button test:"))   # the parent is an optional second argument to help python with cleanup
        self.info = QLineEdit(self)
        self.info.setText("try clicking the button")
        self.state = False
        hbox.addWidget(self.info)
        
        # now add that line to the vertical layout
        lyt.addLayout(hbox)
        
        # create another horizontal layout for a single line
        hbox = QHBoxLayout()   # note: no self for it must not take the Widget size
        
        # add a toggle button
        btn1 = QPushButton("toggle")
        hbox.addWidget(btn1)
        
        # add a quit button
        btn2 = QPushButton("quit")
        hbox.addWidget(btn2)
        
        lyt.addStretch(1)
        lyt.addLayout(hbox)
        
        # make object available from outside the class
        self.close_button = btn2
        
        # add connections
        btn1.clicked.connect(self.on_toggle_button_clicked)
        btn2.clicked.connect(self.close)  # this connects to a QWidget standard function
        
    # this is our callback function
    def on_toggle_button_clicked(self):
        if self.state:
            self.info.setText("try clicking the button")
        else:
            self.info.setText("button clicked :)")
        self.state = not self.state
        
