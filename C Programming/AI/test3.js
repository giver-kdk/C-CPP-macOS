let data = [scrape-data];
// Create a new image element
const imgElement = new Image();
imgElement.src = data[0];

// Create a new DataTransfer object
const dataTransfer = new DataTransfer();

// Add the image data to the DataTransfer object as a Blob
fetch(imgElement.src)
  .then(response => response.blob())
  .then(blob => {
    dataTransfer.items.add(new File([blob], "image.png", {type: "image/png"}));

    // Set the DataTransfer object as the clipboard data
    const clipboardData = new ClipboardEvent("").clipboardData || new DataTransfer();
    clipboardData.items.add(dataTransfer.items[0]);
    navigator.clipboard.write(clipboardData)
      .then(() => console.log("Image copied to clipboard"))
      .catch(error => console.error("Failed to copy image to clipboard:", error));
  });
console.log("Copying...");