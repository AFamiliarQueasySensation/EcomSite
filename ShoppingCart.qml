import QtQuick
import com.company.ItemController

Rectangle {
  id: root

  property bool hidden: true

  height: 400
  width: 250
  radius: 20

  color: "#333333"

  Text {
    id: shoppingCartText

    anchors {
      left: parent.left
      top: parent.top
      margins: 10
    }

    text: "Shopping Cart"
    color: "White"
    font.bold: true
    font.pixelSize: 20
  }

  ListView {
    id: listview

    anchors {
      top: shoppingCartText.bottom
      bottom: addButton.top
      margins: 20
      right: parent.right
      left: parent.left
    }

    clip: true
    model: ItemController
    spacing: 10

    delegate: Rectangle {
      id: delegate

      required property string itemTitle
      required property string itemSeller
      required property url itemImageSource
      required property url itemVideoSource
      required property url itemGifSource
      required property int index

      width: listview.width
      height: 50

      color: "lightgrey"

      Column {
        id: textColumn

        anchors {
          top: parent.top
          left: parent.left
          right: removeButton.left
          margins: 5
        }

        spacing: 5
        Text {
          width: textColumn.width
          elide: Text.ElideRight //truncate to fit width
          fontSizeMode: Text.Fit
          minimumPixelSize: 10 // minumum
          color: "white"
          text: delegate.itemTitle
          font {
            pixelSize: 14
            bold: true
          }
        }
        Text {
          width: textColumn.width
          elide: Text.ElideRight //truncate to fit width
          fontSizeMode: Text.Fit
          minimumPixelSize: 6 // minumum
          color: "gray"
          text: delegate.itemSeller

          font {
            pixelSize: 10
          }
        }
      }

      MouseArea {
        id: delegateMouseArea
        anchors.fill: parent

        onClicked: {
          ItemController.switchToItemByIndex(delegate.index)
        }
      }

      ImageButton {
        id: removeButton
        anchors {
          right: parent.right
          verticalCenter: parent.verticalCenter
          rightMargin: 5
        }

        width: 30
        height: 30

        source: "assets/icons/trashcan.png"

        onClicked: {
          ItemController.removeItem(delegate.index)
        }
      }
    }
  }

  ImageButton {
    id: addButton
    anchors {
      left: parent.left
      bottom: parent.bottom
      margins: 20
    }
    source: "assets/icons/addButton.png"

    height: 32
    width: 32

    onClicked: {
      ItemController.addItem("TestTitle", "SellerTest")
    }
  }

  Behavior on x {
    PropertyAnimation {
      easing.type: Easing.InOutQuad
      duration: 200
    }
  }
}
