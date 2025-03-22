import QtQuick
import com.company.ItemController
import Qt.example.ItemSearch

Rectangle {
  id: root

  property bool hidden: true

  color: "black"

  ListView {
    id: listview
    anchors {
      fill: parent
      margins: 20
    }

    spacing: 10
    clip: true
    model: ItemSearch

    delegate: Rectangle {
      id: delegate
    }
  }
  Behavior on y {
    PropertyAnimation {
      easing.type: Easing.InOutQuad
      duration: 200
    }
  }
} //Rectangle
