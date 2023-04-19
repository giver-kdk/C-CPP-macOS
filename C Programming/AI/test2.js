let inputElement = document.querySelector(".x76ihet.xwmqs3e.x112ta8.xxxdfa6.x9f619.xzsf02u.xmper1u.xo1l8bm.x5yr21d.x1a2a7pz.x1iorvi4.x4uap5.xwib8y2.xkhd6sd.xh8yej3.xha3pab.xngnso2.x1qb5hxa");
// // Create a new file input element
// const fileInputElement = document.createElement("input");
// fileInputElement.type = "file";

// // Add a change event listener to the file input element
// fileInputElement.addEventListener("change", () => {
// 	const file = fileInputElement.files[0];
// 	const reader = new FileReader();

// 	reader.addEventListener("load", () => {
// 		// Create a new DataTransfer object
// 		const dataTransfer = new DataTransfer();

// 		// Create a new image element
// 		const imgElement = new Image();
// 		imgElement.src = reader.result;

// 		// Add the image element to the DataTransfer object
// 		dataTransfer.items.add(imgElement);

// 		// Set the DataTransfer object as the clipboard data
// 		const clipboardData = new ClipboardEvent("").clipboardData || new DataTransfer();
// 		clipboardData.items.add(dataTransfer.items[0]);
// 		inputElement.dispatchEvent(new ClipboardEvent("paste", { clipboardData }));
// 	});

// 	// Read the file as a data URL
// 	reader.readAsDataURL(file);
// });

// // Click the file input element to trigger the "change" event
// fileInputElement.click();
// Add a change event listener to the file input element

// Set the DataTransfer object as the clipboard data
const clipboardData = new ClipboardEvent("").clipboardData;
inputElement.dispatchEvent(new ClipboardEvent("paste", { clipboardData }));


