import QtQuick
import QtQuick.Controls

TextField {
  id: root
  signal textEntered(string text)

  background: Rectangle {
    radius: 10
    gradient: Gradient {
      GradientStop {
        position: 0
        color: "#E3FDF5"
      }
      GradientStop {
        position: 1
        color: "#FFE6FA"
      }
    }
  }

  verticalAlignment: TextField.AlignVCenter
  horizontalAlignment: TextField.AlignHCenter

  font {
    pixelSize: 16
    weight: Font.DemiBold
    family: "Open Sans"
  }

  Keys.onReturnPressed: {
    textEntered(root.text)
    root.focus = false
  }
  Keys.onEscapePressed: {
    root.focus = false
    root.text = ""
  }

  leftPadding: 10
  width: 350
  height: 40
}
