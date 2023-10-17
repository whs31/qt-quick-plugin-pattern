import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import "../js/desc.js" as Gen

Button {
    property color col: "red"
    text: "Click me!"
    Material.background: col
    onPressed: col = Gen.getRandomColor()
}