import QtQuick
import com.company.ItemController
import Qt.example.ItemSearch

/* Search model when searching displays all the items into ta delegate, which are displayed using an index*/
Rectangle {
  id: root

  property bool hidden: true

  color: "black"

  ListView {
    id: listview

    anchors {
      fill: parent
      margins: 10
    }

    spacing: 10
    clip: true
    model: ItemSearch
    visible: !ItemSearch.isSearching
    delegate: Rectangle {

      id: delegate

      required property string itemTitle
      required property string itemSeller
      required property url itemImageSource
      required property url itemVideoSource
      required property url itemGifSource
      required property int index

      width: listview.width
      height: 180
      radius: 5

      color: "grey"

      //Image displayed when searching
      Image {
        id: itemimage
        anchors {
          left: parent.left
          leftMargin: 5
          verticalCenter: parent.verticalCenter
        }
        width: 160
        height: 160
        mipmap: true
        fillMode: Image.PreserveAspectFit

        source: delegate.itemImageSource
      }

      //Column of texts beside the image
      Column {
        id: textColumn
        anchors {
          left: itemimage.left
          right: parent.right
          top: parent.top
          margins: 5
        }

        //Item title
        Text {
          width: textColumn.width
          elide: Text.ElideRight //truncate to fit width
          fontSizeMode: Text.Fit
          minimumPixelSize: 10 // minumum
          color: "White"
          text: delegate.itemTitle
          font {
            family: "Open Sans"
            pixelSize: 32
            bold: true
          }
          anchors {
            left: parent.left
            leftMargin: 170
          }
        }

        // Item Description
        Text {
          width: textColumn.width
          elide: Text.ElideRight //truncate to fit width
          fontSizeMode: Text.Fit
          minimumPixelSize: 6 // minumum
          color: "white"
          text: delegate.itemSeller
          font {
            family: "Open Sans"
            pixelSize: 18
          }
          anchors {
            left: parent.left
            leftMargin: 170
          }
        }
      }
      MouseArea {
        id: delegateMouseArea
        anchors.fill: parent

        onClicked: {
          //Adds the item you click from the delegate to the shopping cart here
          ItemController.addItem(delegate.itemTitle, delegate.itemSeller,
                                 delegate.itemImageSource,
                                 delegate.itemGifSource,
                                 delegate.itemVideoSource)
        }
      }
    }
  }
  Text {
    anchors.centerIn: parent

    color: "grey"
    visible: ItemSearch.isSearching || listview == 0
    text: if (ItemSearch.isSearching) {
            return "Searching..."
          } else if (listview == 0) {
            return "No Results"
          } else {
            return ""
          }
    font {
      pixelSize: 24
      bold: true
    }
  }

  Behavior on y {
    PropertyAnimation {
      easing.type: Easing.InQuad
      duration: 200
    }
  }
}
