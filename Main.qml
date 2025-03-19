import QtQuick
import QtQuick.Layouts
import com.company.ItemController

Window {
  id: root

  width: 640
  height: 480

  visible: true

  title: "Ecom Site"

  Rectangle {
    id: topbar

    anchors {
      top: parent.top
      left: parent.left
      right: parent.right
    }

    height: 50
    color: "#5F8575"

    ImageButton {

      anchors {
        right: parent.right
        verticalCenter: parent.verticalCenter
        rightMargin: 20
      }

      width: 32
      height: 32
      source: "assets/icons/menu_icon.png"

      onClicked: {
        shoppingCart.hidden = !shoppingCart.hidden
      }
    }
  } // Top Bar

  Rectangle {
    id: middlebar
    anchors {
      top: topbar.bottom
      left: parent.left
      right: parent.right
      bottom: bottombar.top
    }

    color: "#578FCA"

    ItemInfoBox {
      id: item
      anchors {
        verticalCenter: parent.verticalCenter
        left: parent.left
        right: parent.right
        margins: 80
      }

    }
  } // Middle Bar

  Rectangle {
    id: bottombar
    anchors {
      bottom: parent.bottom
      left: parent.left
      right: parent.right
    }
    height: 100
    color: "#A1E3F9"

    Row {
      anchors.centerIn: parent
      spacing: 30
      ImageButton {
        id: previousButton

        width: 50
        height: 50
        source: "assets/icons/Previous.png"

        onClicked: {

          ItemController.switchToPreviousItem()
        }
      }

      ImageButton {
        id: nextButton

        width: 50
        height: 50
        source: "assets/icons/next.png"

        onClicked: ItemController.switchToNextItem()
      }
    }
  } // Bottom Bar

  ShoppingCart {
    id: shoppingCart

    anchors {
      top: topbar.bottom
    }

    x: hidden ? parent.width : parent.width - width
  }
} // Window
