import QtQuick

Image {
  id: root

  signal clicked

  opacity: buttonMouseArea.containsMouse ? 0.80 : 1
  fillMode: Image.PreserveAspectFit
  mipmap: true

  MouseArea {
    id: buttonMouseArea
    anchors.fill: parent

    hoverEnabled: true

    onClicked: {
      root.clicked()
    }
  }
}
