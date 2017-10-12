import QtQuick 2.0

Rectangle {
    width: 300
    height: 60
    Row {
        Repeater {
            id:arElements;
            model:arrayStr;
            delegate: ArElement { text: display; width: 30; height: 40}
            Component.onCompleted:
            {
                sorter.sort();
                arElements.model=arrayStr;
            }
        }
    }
}
