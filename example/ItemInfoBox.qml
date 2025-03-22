import QtQuick
import QtMultimedia
import com.company.ItemController
import example

Item {
  id: root
  visible: ItemController.currentItem

  readonly property ItemInfo infoProvider: ItemInfo {}

  Image {
    id: itemImage

    anchors {
      verticalCenter: parent.verticalCenter
      left: parent.left
    }

    width: 150
    height: 150
    source: ItemController.currentItem ? ItemController.currentItem.imageSource : ""
  }

  Video {
    id: video
    width: 150
    height: 150
    source: ItemController.currentItem ? ItemController.currentItem.videoSource : ""
    loops: MediaPlayer.Infinite
    volume: 0
    MouseArea {
      anchors.fill: parent
      onClicked: {
        video.play()
      }
    }
  }

  AnimatedImage {
    id: gifImage

    anchors {
      verticalCenter: parent.verticalCenter
      left: parent.left
    }

    width: 150
    height: 150
    source: ItemController.currentItem ? ItemController.currentItem.gifSource : ""
  }

  Text {
    id: titleText
    anchors {
      bottom: parent.verticalCenter
      left: itemImage.right
      margins: 20
      right: parent.right
    }

    color: "White" // font color
    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
    text: ItemController.currentItem ? ItemController.currentItem.itemName : ""

    font {
      pixelSize: 20
      bold: true
    }
  }
  Text {
    id: descriptionText
    anchors {
      top: parent.verticalCenter
      left: itemImage.right
      topMargin: 5
      leftMargin: 20
      right: parent.right
    }
    color: "White" // font color
    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
    text: ItemController.currentItem ? ItemController.currentItem.sellerName : ""

    font {
      pixelSize: 16
    }
  }

  onVisibleChanged: {
    if (visible) {
      video.play()
    } else {
      video.stop()
      video.seek(0) // restart video
    }
  }
}
