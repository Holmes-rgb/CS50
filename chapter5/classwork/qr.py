import qrcode
qr = qrcode.QRCode(
    version=1,
    error_correction=qrcode.constants.ERROR_CORRECT_L,
    box_size=20,
    border=4,
)
qr.add_data('https://ide.cs50.io/2215d8cbbe1c450c9aac4d777621454a')
qr.make(fit=True)

img = qr.make_image(fill_color="cyan", back_color="white")
img.save("out.png", "PNG")