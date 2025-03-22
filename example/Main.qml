import QtQuick
import QtQuick.Layouts
import com.company.ItemController
import Qt.example.ItemSearch

Window {
  id: root

  width: 1280
  height: 720

  visible: true

  title: "Shopify Site"

  Rectangle {
    id: topbar

    anchors {
      top: parent.top
      left: parent.left
      right: parent.right
    }

    height: 50
    gradient: Gradient {
      GradientStop {
        position: 0.0
        color: "#434343"
      }
      GradientStop {
        position: 1.0
        color: "#434343"
      }
    }

    ImageButton {
      id: menuIcon
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
    SearchField {
      id: searchbar
      color: "black"
      placeholderText: qsTr("Search")

      anchors {
        horizontalCenter: parent.horizontalCenter
        verticalCenter: parent.verticalCenter
      }
      MouseArea {
        anchors.fill: parent
        onClicked: {
          searchbar.forceActiveFocus(Qt.MouseFocusReason)
          searchdisplay.hidden = !searchdisplay.hidden
          item.visible = !item.visible
        }
      }
      Keys.onEscapePressed: {
        item.visible = !item.visible
        searchdisplay.hidden = !searchdisplay.hidden
      }

      onTextEntered: {
        ItemSearch.searchItems(text)
      }
    }
  } // Top Bar

  Rectangle {
    id: middlebar
    anchors {
      top: topbar.bottom
      left: parent.left
      right: parent.right
      bottom: parent.bottom
    }

    gradient: Gradient {
      GradientStop {
        position: 0.0
        color: "#434343"
      }
      GradientStop {
        position: 1.0
        color: "#000000"
      }
    }

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

  ItemSearchDisplay {
    id: searchdisplay
    anchors {
      left: parent.left
      right: parent.right
    }
    height: middlebar.height

    y: hidden ? parent.height : topbar.height
  }

  ShoppingCart {
    id: shoppingCart

    anchors {
      top: topbar.bottom
    }

    x: hidden ? parent.width : parent.width - width
  }
} // Window
