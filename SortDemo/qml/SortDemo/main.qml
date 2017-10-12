import QtQuick 2.0

Rectangle {
    width: 360
    height: 360
    Row {
        Repeater {
            id:arElements;
            model: 3
            ArElement {
                id:arelement
                width: 100; height: 40
            }
        }
    }
    Timer {
           interval: 500; running: true; repeat: true
           onTriggered: arElements.itemAt(0).text="2"
       }
}
