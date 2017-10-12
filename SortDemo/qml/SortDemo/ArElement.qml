import QtQuick 2.0
import QtQuick.Controls 1.0

Rectangle {
    property alias text: arButtontext.text

    id:arButton;
    Text{
        id:arButtontext;
        text:"123"
        font.pixelSize: 12;
        onTextChanged:
        {
            //console.log("Text Changed");
            animateColor.start();
            animateSize.start();
        }
        PropertyAnimation {
            id: animateColor; target: arButtontext; properties: "color"; to: "red"; duration: 100
            onStopped:
            {
                animateColorRevert.start();
            }
        }
        PropertyAnimation {
            id: animateSize; target: arButtontext; properties: "font.pixelSize"; to: "25"; duration: 1000
            onStopped:
            {
                animateSizeRevert.start();
            }
        }

        //Reverse the Changes
        PropertyAnimation {
            id: animateColorRevert; target: arButtontext; properties: "color"; to: "black"; duration: 100
        }
        PropertyAnimation {
            id: animateSizeRevert; target: arButtontext; properties: "font.pixelSize"; to: "12"; duration: 100
        }
    }

}

