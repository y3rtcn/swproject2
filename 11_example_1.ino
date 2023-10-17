if ((dist_raw == 0.0) || (dist_raw > _DIST_MAX)) {
    dist_raw = _DIST_MAX + 10.0;    // Set Higher Value
    digitalWrite(PIN_LED, 1);       // LED OFF
  } else if (dist_raw < _DIST_MIN) {
    dist_raw = _DIST_MIN - 10.0;    // Set Lower Value
    digitalWrite(PIN_LED, 1);       // LED OFF
  } else {    // In desired Range
    digitalWrite(PIN_LED, 0);       // LED ON      
  }

  // Use the previous distance if the current one is out of range
  if ((dist_raw > _DIST_MAX) || (dist_raw < _DIST_MIN)) {
    dist_raw = dist_prev;
  }

  // Update the EMA filter
  dist_ema = _EMA_ALPHA * dist_raw + (1.0 - _EMA_ALPHA) * dist_ema;

  // Store the current distance as the previous one
  dist_prev = dist_ema;
